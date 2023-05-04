typedef long double ld;
const int maxn = 1e5 + 10;
const ld PI = acos(-1);
typedef complex<ld> base;
base wlen_pw[2*maxn];
void fft (vector<base> & a, bool invert) {
	int n = (int) a.size();
 
	for (int i=1, j=0; i<n; ++i) {
		int bit = n >> 1;
		for (; j>=bit; bit>>=1)
			j -= bit;
		j += bit;
		if (i < j)
			swap (a[i], a[j]);
	}
 
	for (int len=2; len<=n; len<<=1) {
		ld ang = 2*PI/len * (invert ? -1 : 1);
		int len2 = len>>1;
		base wlen (cos(ang), sin(ang));
		wlen_pw[0] = base (1, 0);
		for (int i=1; i<len2; ++i)
			wlen_pw[i] = wlen_pw[i-1] * wlen;
 
		for (int i=0; i<n; i+=len) {
			for (int j=0; j<len2; ++j) {
				base u = a[i+j],  v = a[i+j+len2] * wlen_pw[j];
				a[i+j] = u + v;
				a[i+j+len2] = u - v;
			}
		}
	}
	if (invert)
		for (int i=0; i<n; ++i)
			a[i] /= n;
}
 
void multiply (const vector<int> & a, const vector<int> & b, vector<ll> & res) {
	vector<base> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
	size_t n = 1;
	while (n < max (a.size(), b.size()))  n <<= 1;
	n <<= 1;
	fa.resize (n),  fb.resize (n);
 
	fft (fa, false),  fft (fb, false);
	for (size_t i=0; i<n; ++i)
		fa[i] *= fb[i];
	fft (fa, true);
 
	res.resize (n);
	for (size_t i=0; i<n; ++i){
		res[i] = ll (fa[i].real() + 0.5 * (fa[i].real() >= 0 ? 1 : -1));
	}
}