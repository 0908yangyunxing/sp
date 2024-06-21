# Money原本有10000元，重複提款和存款1000元，一共100000次
## race
```
money=-34805000
```
沒有使用 mutex，用很多密集的提款與存款造成 race condition，最終的 Money 會產生錯誤
## norace
```
money=10000
```
有使用 mutex，用很多密集的提款與存款也不會造成 race condition，最終的 Money 正確，依然維持10000元