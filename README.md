# RaspberryPi
#

#### BSCScanService
- Get API KEY [bscscan](https://bscscan.com/apis#tokens)

```python
if __name__ == "__main__":
    bsc_service = BSCScanService(key="API KEY")
    address = "BNB ADDRESS"
    main_wallet = MainWallet(bnb_address=address)
    main_wallet.bsc = bsc_service
    balance = bsc_service.get_account_balance(address=address)
    rounded_balance = round(balance, 5)
    print(f"balance: {rounded_balance}")
    main_wallet.coin_status_check(sleep_minutes=1)

```