#include <iostream>

template<typename T> inline T* create_matrix(size_t c, size_t r) {
	return new T[c * r];
}

template<typename T> inline void delete_matrix(T* a) {
	delete[] a;
}

template<typename T> T* create_matrix_inited(size_t c, size_t r, T v) {
	r *= c;
	c = (size_t)create_matrix<T>(r, 1);
	while (r--) ((T*)c)[r] = v;
	return (T*)c;
}

int* create_e_matrix(size_t c, size_t r) {
	int* a = create_matrix<int>(c, r);
	memset(a, 0, c * r << 2);
	for (int i = std::min(r, c++); i--;) a[i * c] = 1;
	return a;
}

template<typename T> T* transposition_matrix(T* a, size_t r, size_t c) {
	T* b = create_matrix<T>(r, c);
	for (size_t i = c * r; i--;) b[i] = a[i / r + i % r * c];
	return b;
}

template<typename T> void rotate_180deg(T* a) {
	size_t s = _msize(a) / sizeof(T);
	for (size_t i = s-- >> 1; i--;) std::swap(a[i], a[s - i]);
}

void mul_matrix_int(int* a, int b) {
	for (size_t i = (_msize(a) >> 2); i--;) a[i] *= b;
}

int* create_mul_matrix_int(int* a, int b) {
	register int d = _msize(a) >> 2;
	int* c = new int[d];
	while (d--) c[d] = a[d] * b;
	return c;
}

int* create_add_matrix_matrix(int* a, int* b) {
	register int d = _msize(a) >> 2;
	int* c = new int[d];
	while (d--) c[d] = a[d] + b[d];
	return c;
}

int* create_mul_matrix_matrix(int* a, int* b, size_t ac_br, size_t ar, size_t bc) {
	int* c = create_matrix<int>(ar, bc);
	for (size_t i = ar; i--; ) for (size_t q = bc; q--;) {
		c[i * bc + q] = 0;
		for (size_t w = ac_br; w--;) 
			c[i * bc + q] += a[i * ac_br + w] * b[w * bc + q];
	}
	return c;
}

template<typename T> void swap_row(T* m, size_t c, size_t a, size_t b) {
	a *= c;
	b *= c;
	while (c--) std::swap(m[a++], m[b++]);
}

template<typename T> void swap_column(T* m, size_t c, size_t r, size_t a, size_t b) {
	a += c * r;
	b += c * r;
	while (r--) std::swap(m[a -= c], m[b -= c]);
}

template<typename T> T& link_matrix_value(T* m, size_t c, size_t ac, size_t ar) {
	return m[ar * c + ac];
}

int det_matrix(int* m, int s) {
	if (s > 3) {
		int d = 0;
		int* c = create_matrix<int>(s - 1, s - 1);
		for (int i = s; i--;) {
			for (int q = s - 1; q--;) {
				for (int w = s - 1; w--;) {
					c[w * (s - 1) + q] = m[(w + 1) * s + q + (q >= i)];
				}
			};
			d += det_matrix(c, s - 1) * (1 - ((i & 1) << 1)) * m[i];
		}
		delete_matrix<int>(c);
		return d;
	}
	else switch (s) {
	case 3: return m[0] * (m[4] * m[8] - m[5] * m[7]) + m[1] * (m[5] * m[6] - m[3] * m[8]) + m[2] * (m[3] * m[7] - m[4] * m[6]);
	case 2: return m[0] * m[3] - m[1] * m[2];
	case 1: return m[0];
	default: return 1;
	}
}

int main(){
	return 0;
}