(let [lines (rest (line-seq (java.io.BufferedReader. *in*)))
      gao (fn f[x] (loop [s x r []]
                     (if (empty? s) (clojure.string/join "" r)
                       (recur (drop 2 s) (conj r (second s) (first s))))))]
  (println (clojure.string/join "\n" (map gao lines))))