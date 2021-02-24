fibonacci :: Integer -> Integer
fibonacci n
  | n < 2 = n
  | otherwise = fibonacci (n - 1) + fibonacci (n - 2)

fibonacciLINIAR :: Integer->Integer->Integer->Integer
fibonacciLINIAR n val prev
  | n < 1 = prev
  | otherwise = fibonacciLINIAR (n - 1) (val + prev) (val)