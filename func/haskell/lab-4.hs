import System.Random

randomList :: Int -> (Int, Int) -> IO [Int]
randomList size (start, end) = sequence $ replicate size $ randomRIO(start, end)

excludeExceptMonad :: Int -> IO [Int] -> IO [Int]
excludeExceptMonad year list = list >>= (\x -> return . filter (\n -> n == year) $ x)

excludeExcept :: Int -> [Int] -> [Int]
excludeExcept year list = filter (\n -> n == year) list

multiplyList :: Int -> [Int] -> [Int]
multiplyList num list = map (\x -> x * num) list
