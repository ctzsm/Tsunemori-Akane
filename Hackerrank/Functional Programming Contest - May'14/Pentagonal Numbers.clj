(let [parse (fn [x] (Integer. x))
      lines (map #(parse %) (rest (line-seq (java.io.BufferedReader. *in*))))
      solve (fn [x] (/ (- (* 3 x x) x) 2))]
  (println (clojure.string/join "\n" (map #(str (solve %)) lines))))