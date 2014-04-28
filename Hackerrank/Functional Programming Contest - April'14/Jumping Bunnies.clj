(let [parse (fn [x] (map #(Integer. %) (clojure.string/split x #" ")))
  	  lines (line-seq (java.io.BufferedReader. *in*))
	  gcd (fn [a b] (if (zero? b) a (recur b (mod a b))))
	  lcm (fn [a b] (/ (* a b) (gcd a b)))
	  [l1 l2] lines
	  a (parse l2)]
(println (biginteger (reduce lcm 1N a))))