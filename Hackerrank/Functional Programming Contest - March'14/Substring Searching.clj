(let [lines (partition 2 (rest (line-seq (java.io.BufferedReader. *in*))))]
	(println (clojure.string/join "\n" (map #(if (.contains (first %) (second %)) "YES" "NO") lines))))