(let [parse (fn [x] (map #(Integer. %) (clojure.string/split x #" ")))
  	  lines (line-seq (java.io.BufferedReader. *in*))
	  [n] (parse (first lines))
	  a (to-array-2d (map #(parse %) (take n (rest lines))))
	  K (map #(first (parse %)) (drop (+ n 2) lines))
	  tswap (fn f[x d k] (if (> x 0)
		(let [id (dec x) l (aget a id 0) r (aget a id 1) t (= 0 (mod d k))]
			(if t (aset a id 0 r))
			(if t (aset a id 1 l))
			(concat (if t (f r (inc d) k) (f l (inc d) k)) [x] (if t (f l (inc d) k) (f r (inc d) k))))))]
(println (clojure.string/join "\n" (map #(clojure.string/join " " (map str (tswap 1 1 %))) K))))