int n, m, k;
vector<int> v;

bool func(int cur, int cnt,int sz,int f) {
	int i = (cur + 1)%m;
	
	while (i!=f) {
		if ((v[i] - v[cur]+n)%n >= sz) {
			cur = i;
			cnt++;
			if (cnt == k) {
				if ((v[f] - v[cur] + n) % n >= sz) return true;
				return false;
			}
		}
		i=(i+1)%m;
	}

	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	if (k == 1) {
		cout << n << '\n';
		return 0;
	}
	int l = 1, r =n;
	while (l <= r) {
		int mid = (l + r) >> 1;
		bool chk = false;
		for (int i = 0; i < m; i++) {
			if (func(i, 1, mid,i)) {
				chk = true;
				break;
			}
		}
		if (chk) l = mid + 1;
		else r = mid - 1;
	}
	cout << r << '\n';
	return 0;
}
