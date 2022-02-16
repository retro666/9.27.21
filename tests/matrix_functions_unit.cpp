#include "pch.h"
#include "CppUnitTest.h"
#include "..\matrix_functions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(create_matrix1)
	{
	public:
		
		TEST_METHOD(inited){
			int* a = create_matrix_inited(10, 5, 32619573);
			Assert::AreEqual(200ull, _msize(a));
			for (char i = 0; i < 50;) Assert::AreEqual(32619573, a[i++]);
		}
		TEST_METHOD(E) {
			int* a = create_e_matrix<int>(10, 5);
			Assert::AreEqual(200ull, _msize(a));
			for (char i = 0; i < 5; ++i) {
				for (char q = 0; q < 10; ++q) {
					Assert::AreEqual((int)(i == q), a[i * 10 + q]);
				}
			}
		}
	};
	TEST_CLASS(transposition)
	{
	public:

		TEST_METHOD(rec) {
			const int b[][4] = {
				{7545827,	17598209, 40826990, 84130085},
				{14099211,	24013835, 32297376, 39628472},
				{3897710,	28897087, 29644254, 78731641},
				{783165,	34095540, 42048710, 68893305} };
			int* a = transposition_matrix((int*)b, 4, 4);
			Assert::AreEqual(64ull, _msize(a));
			for (char i = 0; i < 4; i++) for (char q = 0; q < 4; q++) Assert::AreEqual(b[i][q], ((int(&)[][4])(a[0]))[q][i]);
		}
		TEST_METHOD(rgc) {
			const int b[][3] = {
				{7545827,	17598209, 40826990},
				{14099211,	24013835, 32297376},
				{3897710,	28897087, 29644254},
				{783165,	34095540, 42048710} };
			int* a = transposition_matrix((int*)b, 4, 3);
			Assert::AreEqual(48ull, _msize(a));
			for (char i = 0; i < 4; i++) for (char q = 0; q < 3; q++) Assert::AreEqual(b[i][q], ((int(&)[][4])(a[0]))[q][i]);
		}
		TEST_METHOD(rlc) {
			const int b[][4] = {
				{7545827,	17598209, 40826990, 84130085},
				{14099211,	24013835, 32297376, 39628472},
				{3897710,	28897087, 29644254, 78731641}};
			int* a = transposition_matrix((int*)b, 3, 4);
			Assert::AreEqual(48ull, _msize(a));
			for (char i = 0; i < 3; i++) for (char q = 0; q < 4; q++) Assert::AreEqual(b[i][q], ((int(&)[][3])(a[0]))[q][i]);
		}
	};
	TEST_CLASS(rotate)
	{
	public:

		TEST_METHOD(rec) {
			const int b[][4] = {
				{7545827,	17598209, 40826990, 84130085},
				{14099211,	24013835, 32297376, 39628472},
				{3897710,	28897087, 29644254, 78731641},
				{783165,	34095540, 42048710, 68893305} };
			int* a = new int[4 * 4];
			memcpy(a, b, 64);
			rotate_180(a, 16);
			for (char i = 0; i < 4; i++) for (char q = 0; q < 4; q++) Assert::AreEqual(b[i][q], ((int(&)[][4])a[0])[3 - i][3 - q]);
		}
		TEST_METHOD(rgc) {
			const int b[][3] = {
				{7545827,	17598209, 40826990},
				{14099211,	24013835, 32297376},
				{3897710,	28897087, 29644254},
				{783165,	34095540, 42048710} };
			int* a = new int[3 * 4];
			memcpy(a, b, 48);
			rotate_180(a, 12);
			for (char i = 0; i < 4; i++) for (char q = 0; q < 3; q++) Assert::AreEqual(b[i][q], ((int(&)[][3])a[0])[3 - i][2 - q]);
		}
		TEST_METHOD(rlc) {
			const int b[][4] = {
				{7545827,	17598209, 40826990, 84130085},
				{14099211,	24013835, 32297376, 39628472},
				{3897710,	28897087, 29644254, 78731641} };
			int* a = new int[4 * 3];
			memcpy(a, b, 48);
			rotate_180(a, 12);
			for (char i = 0; i < 3; i++) for (char q = 0; q < 4; q++) Assert::AreEqual(b[i][q], ((int(&)[][4])a[0])[2 - i][3 - q]);
		}
	};
	TEST_CLASS(muli)
	{
	public:

		TEST_METHOD(m0) {
			const int b[][4] = {
				{7545827,	17598209, 40826990, 84130085},
				{14099211,	24013835, 32297376, 39628472},
				{3897710,	28897087, 29644254, 78731641},
				{783165,	34095540, 42048710, 68893305} };
			int* a = new int[4 * 4];
			memcpy(a, b, 64);
			mul_matrix_val(a, 0, 16);
			for (char i = 0; i < 4; i++) for (char q = 0; q < 4; q++) Assert::AreEqual(0, ((int(&)[][4])a[0])[i][q]);
		}
		TEST_METHOD(m1) {
			const int b[][3] = {
				{7545827,	17598209, 40826990},
				{14099211,	24013835, 32297376},
				{3897710,	28897087, 29644254},
				{783165,	34095540, 42048710} };
			int* a = new int[3 * 4];
			memcpy(a, b, 48);
			mul_matrix_val(a, 1, 12);
			for (char i = 0; i < 4; i++) for (char q = 0; q < 3; q++) Assert::AreEqual(b[i][q], ((int(&)[][3])a[0])[i][q]);
		}
		TEST_METHOD(mi) {
			int b[][4] = {
				{7545827,	17598209, 40826990, 84130085},
				{14099211,	24013835, 32297376, 39628472},
				{3897710,	28897087, 29644254, 78731641} };
			int* a = new int[4 * 3];
			memcpy(a, b, 48);
			mul_matrix_val(a, 25, 12);
			for (char i = 0; i < 12;) ((int*)b)[i++] *= 25;
			for (char i = 0; i < 3; i++) for (char q = 0; q < 4; q++) Assert::AreEqual(b[i][q], ((int(&)[][4])a[0])[i][q]);
		}
	};
	TEST_CLASS(muli_create)
	{
	public:

		TEST_METHOD(m0) {
			const int b[][4] = {
				{7545827,	17598209, 40826990, 84130085},
				{14099211,	24013835, 32297376, 39628472},
				{3897710,	28897087, 29644254, 78731641},
				{783165,	34095540, 42048710, 68893305} };
			int* c = new int[4 * 4];
			memcpy(c, b, 64);
			int* a = create_mul_matrix_val(c, 0, 16);
			for (char i = 0; i < 4; i++) for (char q = 0; q < 4; q++) Assert::AreEqual(0, ((int(&)[][4])a[0])[i][q]);
		}
		TEST_METHOD(m1) {
			const int b[][3] = {
				{7545827,	17598209, 40826990},
				{14099211,	24013835, 32297376},
				{3897710,	28897087, 29644254},
				{783165,	34095540, 42048710} };
			int* c = new int[3 * 4];
			memcpy(c, b, 48);
			int* a = create_mul_matrix_val(c, 1, 12);
			for (char i = 0; i < 4; i++) for (char q = 0; q < 3; q++) Assert::AreEqual(b[i][q], ((int(&)[][3])a[0])[i][q]);
		}
		TEST_METHOD(mi) {
			int b[][4] = {
				{7545827,	17598209, 40826990, 84130085},
				{14099211,	24013835, 32297376, 39628472},
				{3897710,	28897087, 29644254, 78731641} };
			int* c = new int[4 * 3];
			memcpy(c, b, 48);
			int* a = create_mul_matrix_val(c, 25, 12);
			for (char i = 0; i < 12;) ((int*)b)[i++] *= 25;
			for (char i = 0; i < 3; i++) for (char q = 0; q < 4; q++) Assert::AreEqual(b[i][q], ((int(&)[][4])a[0])[i][q]);
		}
	}; 
	TEST_CLASS(addm_create)
	{
	public:

		TEST_METHOD(m) {
			const int b[][4] = {
				{7545827,	17598209, 40826990, 84130085},
				{14099211,	24013835, 32297376, 39628472},
				{3897710,	28897087, 29644254, 78731641},
				{783165,	34095540, 42048710, 68893305}
			},
			c[][4] = {
				{16086432, 52425415, 62849283, 65245538},
				{22548321, 33183625, 49876465, 87877060},
				{19703950, 55660791, 77058099, 98746090},
				{14213235, 46624558, 47129204, 90778662}
			};
			int* d = new int[4 * 4], *e = new int[4 * 4];
			memcpy(d, b, 64);
			memcpy(e, c, 64);
			int* a = create_add_matrix_matrix(d, e, 16);
			for (char i = 0; i < 4; i++) for (char q = 0; q < 4; q++) Assert::AreEqual(b[i][q] + c[i][q], ((int(&)[][4])a[0])[i][q]);
		}
	};
	TEST_CLASS(mulm_create)
	{
	public:

		TEST_METHOD(rec) {
			const int b[][3] = {
				{2,	3,	0},
				{1,	0,	4}};
			const int c[][2] = {
				{1,	0},
				{1,	4},
				{0,	2}};
			const int f[][2] = {
				{5,	12},
				{1,	8}};
			int* d = new int[3 * 2], *e = new int[2 * 3];
			memcpy(d, b, 24);
			memcpy(e, c, 24);
			int* a = create_mul_matrix_matrix(d, e, 3, 2, 2);
			for (char i = 0; i < 2; i++) for (char q = 0; q < 2; q++) Assert::AreEqual(f[i][q], ((int(&)[][2])a[0])[i][q]);
		}
		TEST_METHOD(rnc) {
			const int b[][3] = {
				{2,	3,	4},
				{1,	2,	0},
				{2,	3,	1}};
			const int c[][2] = {
				{1,	2},
				{3,	4},
				{5,	6} };
			const int f[][2] = {
				{31,	40},
				{7,	10},
				{16,	22}};
			int* d = new int[3 * 3], * e = new int[2 * 3];
			memcpy(d, b, 36);
			memcpy(e, c, 24);
			int* a = create_mul_matrix_matrix(d, e, 3, 3, 2);
			for (char i = 0; i < 3; i++) for (char q = 0; q < 2; q++) Assert::AreEqual(f[i][q], ((int(&)[][2])a[0])[i][q]);
		}
	};
	TEST_CLASS(swap_rc)
	{
	public:

		TEST_METHOD(c) {
			const int b[][4] = {
				{7545827,	17598209, 40826990, 84130085},
				{14099211,	24013835, 32297376, 39628472},
				{3897710,	28897087, 29644254, 78731641},
				{783165,	34095540, 42048710, 68893305}};
			int* a = new int[4 * 4];
			memcpy(a, b, 64);
			swap_column(a, 4, 4, 1, 3);
			for (char i = 0; i < 2; i++) for (char q = 0; q < 2; q++) Assert::AreEqual(b[i][q & 1 ? q ^ 2: q], ((int(&)[][4])a[0])[i][q]);
		}
		TEST_METHOD(r) {
			const int b[][4] = { 
				{7545827,	17598209, 40826990, 84130085},
				{14099211,	24013835, 32297376, 39628472},
				{3897710,	28897087, 29644254, 78731641},
				{783165,	34095540, 42048710, 68893305} };
			int* a = new int[4 * 4];
			memcpy(a, b, 64);
			swap_row(a, 4, 1, 3);
			for (char i = 0; i < 2; i++) for (char q = 0; q < 2; q++) Assert::AreEqual(b[i & 1 ? i ^ 2 : i][q], ((int(&)[][4])a[0])[i][q]);
		}
	};
	TEST_CLASS(det)
	{
	public:

		TEST_METHOD(s1) {
			int* a = new int[1 * 1];
			a[0] = 7545827;
			Assert::AreEqual(7545827, det_matrix(a, 1));
		}
		TEST_METHOD(s2) {
			const int b[][2] = {
				{1,	3},
				{7,	9}};
			int* a = new int[2 * 2];
			memcpy(a, b, 16);
			Assert::AreEqual(-12, det_matrix(a, 2));
		}
		TEST_METHOD(s3) {
			const int b[][3] = {
				{1,	-2,	3},
				{0,	7,	4},
				{5,	3,	-3}};
			int* a = new int[3 * 3];
			memcpy(a, b, 36);
			Assert::AreEqual(-178, det_matrix(a, 3));
		}
		TEST_METHOD(s4) {
			const int b[][4] = {
				{1,	0,	1,	2},
				{-3,	1,	-2,	-4},
				{2,	3,	1,	0},
				{-4,	-2,	0,	-7}};
			int* a = new int[4 * 4];
			memcpy(a, b, 64);
			Assert::AreEqual(40, det_matrix(a, 4));
		}
	};
	TEST_CLASS(inverse) {
	public:
		TEST_METHOD(E) {
			const int b[][2] = {
				{0, 1},
				{1, 0}
			}, ans[][2] = {
				{0, 1},
				{1, 0}
			};
			long double* a = inverse_matrix((int(&)[])b, 2);
			for (size_t i = 0; i < 4; ++i) Assert::AreEqual((int)std::roundl(a[i]), ((const int(&)[])(ans[0]))[i]);
		}
		TEST_METHOD(integer0) {
			const int b[][3] = {
				{1, 5, 1},
				{3, 2, 1},
				{6, -2, 1}
			}, ans[][3] = {
				{4,	-7, 	3},
				{3,	-5,	2},
				{-18,	32,	-13}
			};
			long double* a = inverse_matrix((int(&)[])b, 3);
			for (size_t i = 0; i < 9; ++i) Assert::AreEqual((int)std::roundl(a[i]), ((const int(&)[])(ans[0]))[i]);
		}
		TEST_METHOD(integer1) {
			const int b[][4] = {
				{1,	4,	2,	3},
				{1,	-2,	1,	-2},
				{1,	-1,	1,	1},
				{0,	-10,	-2,	-5}
			}, ans[][4] = {
				{33,	-6,	-26,	17},
				{6,	-1,	-5,	3},
				{-25,	5,	20,	-13},
				{-2,	0,	2,	-1}
			};
			long double* a = inverse_matrix((int(&)[])b, 4);
			for (size_t i = 0; i < 16; ++i) Assert::AreEqual((int)std::roundl(a[i]), ((const int(&)[])(ans[0]))[i]);
		}
		TEST_METHOD(l_double) {
			const int b[][4] = {
				{1,	0,	1,	2},
				{-3,	1,	-2,	-4},
				{2,	3,	1,	0},
				{-4,	-2,	0,	-7}
			};
			const long double ans[][4] = {
				{-57.l / 40,	-5.l / 8,	7.l / 40,	-1.l / 20},
				{23.l / 40,	3.l / 8,	7.l / 40,	-1.l / 20},
				{9.l / 8,	1.l / 8,	1.l / 8,	1.l / 4},
				{13.l / 20,	1.l / 4,	-3.l / 20,	-1.l / 10}
			};
			long double* a = inverse_matrix((int(&)[])b, 4);
			for (size_t i = 0; i < 16; ++i) Assert::AreEqual(std::abs(a[i] - ((const long double(&)[])(ans[0]))[i]) < 1e-12, true);
		}
	};
}
