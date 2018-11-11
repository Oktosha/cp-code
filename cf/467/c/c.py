k, d, t = map(int, input().split())
w = t * 2
period = ((k + d - 1) // d) * d
slow_per_period = (d - (k % d)) % d
period_w = slow_per_period + (period - slow_per_period) * 2
n_periods = w // period_w
remaining_w = w % period_w
remaining_time = 0

if remaining_w <= (period - slow_per_period) * 2:
	remaining_time = remaining_w / 2
else:
	slow_remaining_w = remaining_w - (period - slow_per_period) * 2
	remaining_time = (period - slow_per_period) + slow_remaining_w

print(n_periods * period + remaining_time)