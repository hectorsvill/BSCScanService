# BSCScanService.py
# by @hectorsvill
# https://bscscan.com/apis#tokens

import time    
import requests

class BSCScanService:
    BALANCE_OFFSET_9D = 0.000000001
    BALANCE_OFFSET_18D = 0.000000000000000001


    def __init__(self, key):
        self.key = key
    
    url = f"https://api.bscscan.com/api"

    def get_account_balance(self, address):
        parameters = {
            'module': 'account',
            'action': 'balance',
            'address': address,
            'tag': 'latest',
            'apikey': self.key,
        }

        response = requests.get(self.url, params=parameters)
        result = response.json()['result']
        return float(result) * self.BALANCE_OFFSET_18D
    
    def get_bep20_token_account_balance(self, token_contract_address, address):
        parameters = {
            'module': 'account',
            'action': 'tokenbalance',
            'contractaddress': token_contract_address,
            'address': address,
            'tag': 'latest',
            'apikey': self.key
        }
        
        response = requests.get(self.url, params=parameters)
        result = response.json()['result']
        return float(result) * self.BALANCE_OFFSET_9D


class MainWallet:
    safemoon_contract_address = "0x8076c74c5e3f5852037f31ff0093eeb8c8add8d3"
    foxfinanace_contract_address = "0xFAd8E46123D7b4e77496491769C167FF894d2ACB"
    safemars_contract_address = "0x3aD9594151886Ce8538C1ff615EFa2385a8C3A88"

    def __init__(self, bnb_address):
        self.bnb_address = bnb_address
        self.bsc = None

    @staticmethod
    def number_comma_format(num):
        return '{:,}'.format(num)

    def coin_status_check(self, sleep_minutes, count=10):
        safemoon_balance_last = 0
        fox_balance_last = 0
        safemars_balance_last = 0
        
        index = 0

        while index < count:            
            fox_balance = self.bsc.get_bep20_token_account_balance(token_contract_address=self.foxfinanace_contract_address, address=self.bnb_address)
            fox_balance_rounded = round(fox_balance, 2)
            fox_balance_diff = round(fox_balance - fox_balance_last, 2)
            
            safemars_balance = self.bsc.get_bep20_token_account_balance(token_contract_address=self.safemars_contract_address, address=self.bnb_address)
            safemars_balance_rounded = round(safemars_balance, 2)
            safemars_balance_diff = round(safemars_balance - safemars_balance_last, 2)

            safemoon_balance = self.bsc.get_bep20_token_account_balance(token_contract_address=self.safemoon_contract_address, address=self.bnb_address)
            safemoon_balance_rounded = round(safemoon_balance, 2)
            safemoon_balance_diff = round(safemoon_balance - safemoon_balance_last, 2)

            fox_status_str = f"FOX       : {self.number_comma_format(num=fox_balance_rounded)} + {self.number_comma_format(num=fox_balance_diff)}"
            safemars_status_str = f"SAFEMARS  : {self.number_comma_format(num=safemars_balance_rounded)} + {self.number_comma_format(num=safemars_balance_diff)} "
            safemoon_status_str = f"SAFEMOON  : {self.number_comma_format(num=safemoon_balance_rounded)} + {self.number_comma_format(num=safemoon_balance_diff)}"

            if index == 0:
                print(f"Starting to observe address: {self.bnb_address}\n\n")
            else:
                print(F"address: {self.bnb_address}\n{fox_status_str}\n{safemars_status_str}\n{safemoon_status_str}\n")

            fox_balance_last = fox_balance
            safemars_balance_last = safemars_balance
            safemoon_balance_last = safemoon_balance

            time.sleep(60 * sleep_minutes)

            index += 1


if __name__ == "__main__":
    bsc_service = BSCScanService(key="API KEY")
    address = "BNB ADDRESS"
    main_wallet = MainWallet(bnb_address=address)
    main_wallet.bsc = bsc_service
    balance = bsc_service.get_account_balance(address=address)
    rounded_balance = round(balance, 5)
    print(f"balance: {rounded_balance}")
    main_wallet.coin_status_check(sleep_minutes=1)

