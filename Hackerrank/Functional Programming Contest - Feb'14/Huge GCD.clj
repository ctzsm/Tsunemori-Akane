(let [parse (fn [x] (map #(Integer. %) (clojure.string/split x #" ")))
      lines (line-seq (java.io.BufferedReader. *in*))
      gcd (fn [a b] (if (zero? b) a (recur b (mod a b))))
      [l1 l2 l3 l4] lines
      a (reduce * 1N (parse l2))
      b (reduce * 1N (parse l4))]
  (println (int (mod (gcd a b) 1000000007))))