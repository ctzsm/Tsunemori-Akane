(let [parse (fn [x] (map #(Integer. %) (clojure.string/split x #" ")))
      [line] (line-seq (java.io.BufferedReader. *in*))
      a (apply * (parse line))]
  (println (double (* a (apply + (map #(/ 1 (inc %)) (range a)))))))