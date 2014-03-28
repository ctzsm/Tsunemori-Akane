{-# LANGUAGE BangPatterns #-}
{-# OPTIONS_GHC -funbox-strict-fields #-}
import Control.Monad
import Data.List
import Data.Maybe
import Data.Int
import Data.Tuple
import Data.Char (isSpace)
import qualified Data.IntMap as M
import qualified Data.ByteString.Lazy.Char8 as L

data SegTree = Null | Node SegTree SegTree Int Int Int

getValue :: SegTree -> Int
getValue (Node left right l r v) = v

build :: [Int] -> Int -> Int -> SegTree
build a l r | l == r = Node Null Null l r (a!!l)
build a l r = Node left right l r v
  where left  = build a l m
        right = build a (m + 1) r
        m     = (l + r) `div` 2
        v     = min (getValue left) (getValue right)

query :: Int -> Int -> SegTree -> Int
query begin end = query'
  where query' Null = 1000001
        query' (Node _ _ l r _) | r < begin || end < l = 1000001
        query' (Node _ _ l r v) | begin <= l && r <= end = v
        query' (Node left right _ _ _) = min (query' left) (query' right)

makeTuple::[Int]->[(Int,Int)]
makeTuple [ ] = []
makeTuple [_] = []
makeTuple (a:b:c) = (a,b) : makeTuple c

parseInput = do
    n <- readInt
    m <- readInt
    a <- readInts n
    nums <- readInts (2*m)
    return (n, a, makeTuple nums)

main = do
  c <- L.getContents
  let ((n, a, q), _) = runParser parseInput c
  let st = build a 0 (n-1)
  putStr $ unlines $ map show $ [query i j st | (i, j) <- q]

data Parser a = Parser {runParser :: L.ByteString -> (a, L.ByteString)}
instance Monad Parser where
  return x  = Parser (\c -> (x, c))
  mx >>= my = Parser f
    where f c = let (x, c')  = runParser mx c
                    (y, c'') = runParser (my x) c'
                in (y, c'')

get :: Parser L.ByteString
get = Parser (\c -> (c, c))

put :: L.ByteString -> Parser ()
put c = Parser (\_ -> ((), c))
-- End of State monad

skipSpace :: Parser ()
skipSpace = do
    c <- get
    let (space, next) = L.span isSpace c
    put next

readInt :: Parser Int
readInt = do
    skipSpace
    c <- get
    let Just (n, rest) = L.readInt c
    put rest
    return n

readInts :: Int -> Parser [Int]
readInts count = mapM (const readInt) [1..count]
