(let [parse (fn [x] (map #(Integer. %) (clojure.string/split x #" ")))
	  gcd (fn [a b] (if (zero? b) a (recur b (mod a b))))
  	  calc (fn [x] (loop [u (int (Math/sqrt x)) res 0 i 1] 
			(if (> i u) (- (* res 2) (if (= x (* u u)) 1 0)) 
				(recur u (if (= 0 (mod x i)) (inc res) res) (inc i)))))
  	  lines (rest (line-seq (java.io.BufferedReader. *in*)))]
(println (clojure.string/join "\n" (map #(str (calc (apply gcd (parse %)))) lines))))