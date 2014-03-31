(let [parse (fn [x] (map #(Integer. %) (clojure.string/split x #" ")))
  	  lines (line-seq (java.io.BufferedReader. *in*))
	  [n k] (parse (first lines))
	  a (reverse (sort (parse (second lines))))
      check (fn [x]
        (loop [a a]
          (cond (empty? a) -1
				(= 0 (mod x (first a))) (first a)
				:else (recur (rest a)))))
	  calc (fn [n]
	    (loop [n n res []] 
	      (let [b (check n)]
			(cond (= 1 n) (reductions * (reverse (conj res 1)))
				  (= -1 b) [-1]
				  :else (recur (quot n b) (conj res b))))))]
(println (clojure.string/join " " (map str (calc n)))))