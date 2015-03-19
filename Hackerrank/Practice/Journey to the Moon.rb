class UnionFindSet
	def initialize(n)
		@f = Array.new(n)
		for i in 0...n
			@f[i] = i
		end
	end
	def find(x)
		return x if x == @f[x]
		@f[x] = find(@f[x])
	end
	def union(x, y)
		fx, fy = find(x), find(y)
		return if fx == fy
		@f[fx] = fy
	end
	def res
		h = @f.inject(Hash.new(0)) {|hash, i| hash[find(i)] += 1; hash}
		v = h.values
		s = Array.new(v.length)
		s[0] = v[0]
		for i in 1...v.length
			s[i] = s[i - 1] + v[i]
		end
		res = 0
		for i in 0...(v.length - 1)
			res += v[i + 1] * s[i]
		end
		res
	end
end

n, i = gets.split.map {|x| x.to_i}

ufs = UnionFindSet.new(n)
for _ in 1..i
	x, y = gets.split.map{|x| x.to_i}
	ufs.union(x, y)
end

puts ufs.res