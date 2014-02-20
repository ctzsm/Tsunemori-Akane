import Data.Char
import Data.Maybe
import qualified Data.HashMap.Strict as HM
import qualified Data.ByteString.Char8 as BS
import System.IO (hFlush, stdout)

parse :: [Char] -> [Char]
parse [] = []
parse (x:xs)
  | x `elem` "<>+-[].," = x : parse xs
  | otherwise = parse xs

genJmp :: String -> Int -> [Int] -> HM.HashMap Int Int -> HM.HashMap Int Int
genJmp [] _ stack jump = jump
genJmp (c:code) idx stack jump
  | c == '['  = genJmp code (idx+1) (idx:stack) jump
  | c == ']'  = genJmp code (idx+1) (tail stack) (HM.insert (head stack) idx (HM.insert idx (head stack) jump))
  | otherwise = genJmp code (idx+1) stack jump

getMp :: Int -> HM.HashMap Int Int -> Int
getMp idx mp = HM.lookupDefault 0 idx mp

putMp :: Int -> Int -> HM.HashMap Int Int -> HM.HashMap Int Int
putMp idx val mp = HM.insert idx val mp

ipt:: Int -> Int -> HM.HashMap Int Int -> [Char] -> HM.HashMap Int Int -> Int -> [Char] -> IO()
ipt cIdx mIdx mem code jump step stream@(x:xs)
  | step >= 100000 = (putStr "\nPROCESS TIME OUT. KILLED!!!")
  | cIdx == length code = return ()
  | cmd == ',' = ipt (cIdx+1) mIdx (putMp mIdx (ord x) mem) code jump nstep xs
  | cmd == '+' = ipt (cIdx+1) mIdx (putMp mIdx (((getMp mIdx mem)+1)`rem`256) mem) code jump nstep stream
  | cmd == '-' = ipt (cIdx+1) mIdx (putMp mIdx (((getMp mIdx mem)-1+256)`rem`256) mem) code jump nstep stream
  | cmd == '.' = (putChar. chr $ HM.lookupDefault 0 mIdx mem) >> hFlush stdout >>
                 ipt (cIdx+1) mIdx mem code jump nstep stream
  | cmd == '>' = ipt (cIdx+1) (mIdx+1) mem code jump nstep stream
  | cmd == '<' = ipt (cIdx+1) (mIdx-1) mem code jump nstep stream
  | cmd == '[' && (getMp mIdx mem) == 0 = ipt (getMp cIdx jump) mIdx mem code jump nstep stream
  | cmd == '[' = ipt (cIdx+1) mIdx mem code jump nstep stream
  | cmd == ']' && (getMp mIdx mem) /= 0 = ipt (getMp cIdx jump) mIdx mem code jump nstep stream
  | cmd == ']' = ipt (cIdx+1) mIdx mem code jump nstep stream
  where
    cmd = code!!cIdx
    nstep = step + 1

main :: IO ()
main = do
  [n, m] <- getArray
  stream <- getLine
  content <- getContents
  let
    code = concat. map parse. lines $ content
    jump = genJmp code 0 [] HM.empty
  ipt 0 0 HM.empty code jump 0 stream
  where
    getArray = fmap (map (fst . fromJust . BS.readInt) . BS.words) BS.getLine
