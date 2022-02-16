#pragma once

template<typename T> T* create_matrix_inited(size_t col, size_t row, T val) {
	col = (size_t)(new T[row *= col]);
	while (row--) {
		((T*)col)[row] = val;
	}
	return (T*)col;
}

template<typename T> T* create_e_matrix(size_t col, size_t row) {
	T* e = new T[col * row];
	while (row--) {
		for (size_t i = col; i--; ) {
			e[row * col + i] = row == i;
		}
	}
	return e;
}

template<typename T> T* transposition_matrix(T* src, size_t row, size_t col) {
	T* dst = new T[row * col];
	for (size_t i = col * row; i--;) {
		dst[i] = src[i / row + i % row * col];
	}
	return dst;
}

template<typename T> void rotate_180(T* matrix, size_t square) {
	for (size_t i = square-- >> 1; i--;) {
		std::swap(matrix[i], matrix[square - i]);
	}
}

template<typename T1, typename T2>void mul_matrix_val(T1* matrix, T2 val, size_t square) {
	while (square--) {
		matrix[square] *= val;
	}
}

template<typename T1, typename T2>T1* create_mul_matrix_val(const T1* matrix, T2 val, size_t square) {
	T1* dst = new T1[square];
	while (square--) {
		dst[square] = matrix[square] * val;
	}
	return dst;
}

template<typename T>T* create_add_matrix_matrix(const T* a, const T* b, size_t square) {
	T* sum = new T[square];
	while (square--) {
		sum[square] = a[square] + b[square];
	}
	return sum;
}

template<typename T>T* create_mul_matrix_matrix(const T* a, const T* b, size_t a_col_b_row, size_t a_row, size_t b_col) {
	T* dst = new T[a_row * b_col];
	for (; a_row--; ) {
		for (size_t q = b_col; q--;) {
			dst[a_row * b_col + q] = 0;
			for (size_t w = a_col_b_row; w--;)
				dst[a_row * b_col + q] += a[a_row * a_col_b_row + w] * b[w * b_col + q];
		}
	}
	return dst;
}

template<typename T> void swap_row(T* matrix, size_t col, size_t row1, size_t row2) {
	row1 *= col;
	row2 *= col;
	while (col--) std::swap(matrix[row1++], matrix[row2++]);
}

template<typename T> void swap_column(T* matrix, size_t col, size_t row, size_t col1, size_t col2) {
	col1 += col * row;
	col2 += col * row;
	while (row--) std::swap(matrix[col1 -= col], matrix[col2 -= col]);
}

template<typename T>T det_matrix(const T* matrix, size_t diag) {

	if (diag > 3) {
		T d = 0;
		T* c = new T[(diag - 1) * (diag - 1)];
		for (int i = diag; i--;) {
			for (int q = diag - 1; q--;) {
				for (int w = diag - 1; w--;) {
					c[w * (diag - 1) + q] = matrix[(w + 1) * diag + q + (q >= i)];
				}
			};
			d += det_matrix(c, diag - 1) * (1 - ((i & 1) << 1)) * matrix[i];
		}
		delete[] c;
		return d;
	}
	else switch (diag) {
	case 3: return matrix[0] * (matrix[4] * matrix[8] - matrix[5] * matrix[7]) + matrix[1] * (matrix[5] * matrix[6] - matrix[3] * matrix[8]) + matrix[2] * (matrix[3] * matrix[7] - matrix[4] * matrix[6]);
	case 2: return matrix[0] * matrix[3] - matrix[1] * matrix[2];
	case 1: return matrix[0];
	default: return 1;
	}
}

template<typename T>long double* inverse_matrix(const T* matrix, size_t diag) {
	long double *dst = create_e_matrix<long double>(diag, diag), *src = new long double[diag * diag];
	for (size_t i = diag * diag; i--;) src[i] = matrix[i];
	for (size_t i = diag; i; ) {
		if (!src[--i * (diag + 1)]) {
			size_t q = diag;
			while (--q && !src[q * diag + i]);
			if (q || src[q * diag + i]) {
				swap_row(src, diag, i, q);
				swap_row(dst, diag, i, q);
			}
			else {
				delete[] dst;
				dst = 0;
				goto RET;
			}
		}
		for (size_t q = diag; q; --q) {
			if ((i + 1) != q && src[i * (diag + 1) - (i - q + 1) * diag]) {
				long double diff = (long double)src[i * (diag + 1) - (i - q + 1) * diag] / src[i * (diag + 1)];
				for (size_t w = 0; w < diag; ++w) {
					if (w < i) {
						src[(q - 1) * diag + w] -= src[i * diag + w] * diff;
					}
					else if (w > i){
						dst[(q - 1) * diag + w] -= dst[i * diag + w] * diff;
					}
				}
				src[(q - 1) * diag + i] = 0;
				dst[(q - 1) * diag + i] = -diff;
			}
		}
	}
	for (size_t i = diag; i--;) {
		for (size_t q = diag; q--;) {
			dst[i * diag + q] /= src[i * (diag + 1)];
		}
	}
RET:	delete[] src;
	return dst;
}
