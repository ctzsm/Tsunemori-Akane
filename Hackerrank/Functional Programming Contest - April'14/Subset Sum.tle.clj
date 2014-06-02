(let [parse (fn [x] (map #(biginteger %) (clojure.string/split x #" ")))
      lines (map parse (line-seq (java.io.BufferedReader. *in*)))
      a (reductions + 0N (sort > (second lines)))
      l (count a)
      S (flatten (drop 3 lines))
      solve (fn [x] (let [idx (java.util.Collections/binarySearch a x compare)]
                      (cond 
                        (= (- 0 1 l) idx) -1 
                        (< idx 0) (- 0 1 idx)
                        :else idx)))]
  (println (clojure.string/join "\n" (map #(str (solve %)) S))))