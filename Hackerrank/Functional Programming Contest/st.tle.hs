import Prelude
import Data.Bits
import Data.Int
import Data.List
import Data.Maybe
import Data.Array.IArray
import Data.Array.IO
import Data.Array.Unboxed
import Control.Monad
import Data.Maybe
import qualified Data.IntMap as M
import qualified Data.ByteString.Char8 as C

log2 :: Int -> Int
log2 x = log2' 0 x
  where
    log2' n 0 = n-1
    log2' n x = log2' (n+1) (shiftR x 1)


m :: (UArray Int Int) -> Array (Int, Int) Int
m a =
  let
    n = snd (bounds a) - fst (bounds a) + 1
    r = array ((1, 1), (n, log2 n)) [ ((i, j), m' (i, j)) | i <- [1..n], j <- [1..log2 n] ]
    m' (i, 1)
      | i < n && a! i <= a! (i+1) = i
      | otherwise = i+1
    m' (i, j)
      | i+2^j-1 > n = rmq (i, n)
      | (a! (r! ( i, j-1 )))  <=  a! (r! (b, j-1 ))  =  r! (i, j-1)
      | otherwise  =  r! (b, j-1)
      where b = i + 2^(j-1)
    rmq :: (Int, Int) -> Int
    rmq (i, j)
      | i == j = i
      | j == i + 1 = if (a! i) <= (a! j) then i else j
      | a! i1 <= a! j1 = i1
      | otherwise = j1
      where
        i1 = r! (i, k)
        j1 = r! (j-2^k+1, k)
        k = log2 (j-i)
  in r

data RMQ = RMQ (UArray Int Int) (Array (Int, Int) Int)

rmq :: [Int] -> RMQ
rmq x = let a = listArray (1, length x) x in RMQ a (m a)

query :: RMQ -> Int -> Int -> Int
query (RMQ a m) i j
  | i == j = i
  | j == i + 1 = if a! i <= a! j then i else j
  | a! i1 <= a! j1 = i1
  | otherwise = j1
  where
    n = snd (bounds a) - fst (bounds a) + 1
    i1 = m! (i, k)
    j1 = m! (j-2^k+1, k)
    k = log2 (j-i)

main = do
  [n, m] <- getArray
  a <- getArray
  let st = rmq a
  q <- replicateM m getArray
  putStr $ unlines $ map show $ [a!!((query st (i + 1) (j + 1)) - 1) | [i, j] <- q]
  where
    getArray = fmap (map (fst . fromJust . C.readInt) . C.words) C.getLine
