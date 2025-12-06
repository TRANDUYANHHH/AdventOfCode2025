A = []
for i in range(4):
	tt = list(map(int, input().split()))
	A.append(tt)
B = list(input().split())

n = 1000
ans = 0
for i in range(n):
	if B[i] == "*":
		tt = 1
		for j in range(4):
			tt *= A[j][i]
		ans += tt;
	else:
		tt = 0
		for j in range(4):
			tt += A[j][i]
		ans += tt

print(ans)
