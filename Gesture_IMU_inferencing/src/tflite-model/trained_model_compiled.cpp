/* Generated by Edge Impulse
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
// Generated on: 19.03.2023 23:07:50

#include <stdio.h>
#include <stdlib.h>
#include "edge-impulse-sdk/tensorflow/lite/c/builtin_op_data.h"
#include "edge-impulse-sdk/tensorflow/lite/c/common.h"
#include "edge-impulse-sdk/tensorflow/lite/micro/micro_mutable_op_resolver.h"
#include "edge-impulse-sdk/porting/ei_classifier_porting.h"

#if EI_CLASSIFIER_PRINT_STATE
#if defined(__cplusplus) && EI_C_LINKAGE == 1
extern "C" {
    extern void ei_printf(const char *format, ...);
}
#else
extern void ei_printf(const char *format, ...);
#endif
#endif

#if defined __GNUC__
#define ALIGN(X) __attribute__((aligned(X)))
#elif defined _MSC_VER
#define ALIGN(X) __declspec(align(X))
#elif defined __TASKING__
#define ALIGN(X) __align(X)
#endif

#ifndef EI_MAX_SCRATCH_BUFFER_COUNT
#define EI_MAX_SCRATCH_BUFFER_COUNT 4
#endif // EI_MAX_SCRATCH_BUFFER_COUNT

#ifndef EI_MAX_OVERFLOW_BUFFER_COUNT
#define EI_MAX_OVERFLOW_BUFFER_COUNT 10
#endif // EI_MAX_OVERFLOW_BUFFER_COUNT

using namespace tflite;
using namespace tflite::ops;
using namespace tflite::ops::micro;

namespace {

constexpr int kTensorArenaSize = 368;

#if defined(EI_CLASSIFIER_ALLOCATION_STATIC)
uint8_t tensor_arena[kTensorArenaSize] ALIGN(16);
#elif defined(EI_CLASSIFIER_ALLOCATION_STATIC_HIMAX)
#pragma Bss(".tensor_arena")
uint8_t tensor_arena[kTensorArenaSize] ALIGN(16);
#pragma Bss()
#elif defined(EI_CLASSIFIER_ALLOCATION_STATIC_HIMAX_GNU)
uint8_t tensor_arena[kTensorArenaSize] ALIGN(16) __attribute__((section(".tensor_arena")));
#else
#define EI_CLASSIFIER_ALLOCATION_HEAP 1
uint8_t* tensor_arena = NULL;
#endif

static uint8_t* tensor_boundary;
static uint8_t* current_location;

template <int SZ, class T> struct TfArray {
  int sz; T elem[SZ];
};
enum used_operators_e {
  OP_FULLY_CONNECTED, OP_SOFTMAX,  OP_LAST
};
struct TensorInfo_t { // subset of TfLiteTensor used for initialization from constant memory
  TfLiteAllocationType allocation_type;
  TfLiteType type;
  void* data;
  TfLiteIntArray* dims;
  size_t bytes;
  TfLiteQuantization quantization;
};
struct NodeInfo_t { // subset of TfLiteNode used for initialization from constant memory
  struct TfLiteIntArray* inputs;
  struct TfLiteIntArray* outputs;
  void* builtin_data;
  used_operators_e used_op_index;
};

TfLiteContext ctx{};
TfLiteTensor tflTensors[14];
TfLiteEvalTensor tflEvalTensors[14];
TfLiteRegistration registrations[OP_LAST];
TfLiteNode tflNodes[5];

const TfArray<2, int> tensor_dimension0 = { 2, { 1,99 } };
const TfArray<1, float> quant0_scale = { 1, { 0.95510858297348022, } };
const TfArray<1, int> quant0_zero = { 1, { -124 } };
const TfLiteAffineQuantization quant0 = { (TfLiteFloatArray*)&quant0_scale, (TfLiteIntArray*)&quant0_zero, 0 };
const ALIGN(16) int8_t tensor_data1[20*99] = { 
  -35, -54, -39, 14, -3, 13, -43, -36, -39, 18, 64, -28, -65, 75, 30, 64, 59, -15, 46, -34, 56, -50, 61, -44, -35, -30, -49, 31, -19, -16, -34, -49, 16, 57, 16, -20, -25, 46, 23, -1, 46, 64, 45, 36, -42, 14, -15, 35, -21, 16, 36, 54, -44, 55, 15, 17, 21, -8, -3, 7, 13, -10, -25, -11, -23, -11, 38, 33, -9, -37, 60, -26, 3, 14, 0, 66, 45, 43, -8, 37, 43, 29, 10, 41, -5, 18, -22, 19, -5, 36, 41, -40, 15, 37, 7, -13, 20, 30, 8, 
  8, 14, 1, -23, 13, 57, 38, 49, -49, 40, 32, -28, -13, -51, -34, -24, -22, -50, 42, 27, -4, -33, -48, -34, 19, -34, 15, 29, -32, 3, 48, 55, -58, -10, -55, 53, -19, 33, 42, -29, -30, 11, 12, 2, -50, -56, 16, -3, -11, -33, 37, 60, -55, -29, 55, -9, -53, 59, -12, -45, 51, 5, -33, 37, -20, -30, 21, -40, 36, -14, -61, 31, -16, -33, 32, 7, -46, -53, 34, -54, 46, -35, -51, -60, -27, -8, -48, 47, -21, -56, 50, -3, -51, -42, -61, 51, 2, 51, -60, 
  6, -66, -43, 31, 6, 19, -51, -8, -31, 12, -14, -10, -67, -1, 37, -46, -36, -9, 55, -53, 45, -4, -26, 3, -17, 56, 11, -26, -5, -31, -35, 50, -48, 28, -47, 27, 19, -3, -24, -33, 54, -6, 3, 0, -9, 13, 47, -10, 66, -42, 61, 4, 16, -36, 44, 35, 45, 22, 24, 50, 27, -53, -48, 26, 33, -39, -23, 4, 25, 60, 49, 32, -17, 63, -14, 41, -36, -13, -39, -16, 19, -24, -40, 23, 52, 62, -2, 34, -39, 26, -23, 20, -53, -14, 63, 25, 45, -2, 33, 
  -59, -16, -48, 25, 16, 18, -42, 9, 9, 52, 0, -52, 10, 27, 5, -30, -16, -13, 57, 35, -60, -38, 60, -5, -8, 55, 4, -20, 46, 11, 0, 44, 4, -49, -14, 45, 14, -12, -45, 3, 3, -11, -14, 33, -45, -38, 45, -45, 34, 37, 51, -35, -24, 54, -55, -35, 32, 1, 39, -41, -56, -32, -13, 38, -33, 18, -18, -59, -58, 22, 28, -21, 0, -37, 7, -43, -51, 24, -29, 35, 35, -34, -33, 7, 31, 33, 46, -31, 51, -19, -2, -40, -24, 38, 35, -50, -46, -25, 34, 
  21, 17, -19, 55, 38, 73, -25, -2, 34, 41, 43, 3, -46, 24, -39, 9, -20, -19, 21, 17, 15, -20, -20, -12, 20, -12, 65, 41, 68, 14, 18, -20, -16, 38, -50, 5, 50, 47, -28, -17, 40, -35, -25, -3, -45, 30, 70, 63, 49, 36, 42, -37, 28, -16, 55, -10, 64, -22, 39, 31, -28, 27, -5, -20, 72, 10, 19, 16, -33, -41, -9, 14, 8, 25, 32, 42, 31, -12, 9, 89, -11, 26, 27, -52, 18, -21, -30, -54, -56, 7, -38, 35, 25, -19, 53, -2, -37, 22, 49, 
  15, -16, -18, -19, -13, 9, 0, 5, -18, -67, -47, -27, 98, -64, 41, 10, -30, 24, 43, 55, -25, -51, -6, 9, -68, 21, 6, -33, 29, 15, 24, 55, -2, 59, 1, 14, -14, 9, 51, -37, -8, 10, 46, 29, -17, 10, -67, 28, -18, -13, -17, -6, -27, -35, -17, 45, -13, -37, 33, 1, -18, -6, 44, -3, 7, -6, 36, -28, 24, -54, -66, -37, -39, -61, -43, -68, 10, 95, 12, -8, -47, 29, 35, 27, 91, 84, 12, 54, -27, 11, 15, 14, -49, 15, -34, 12, 33, 64, -27, 
  -47, 58, -2, -24, -25, 16, 16, -14, -29, 32, -51, -50, -71, -38, 49, 11, -16, 24, 12, -26, 6, -12, 50, -61, 31, -1, -33, 7, 12, -19, 24, -21, -40, -10, -30, -18, 12, 39, 3, -26, 45, 0, -55, -35, -14, 24, 49, 50, 30, 25, 19, 5, 38, -24, -60, 24, -32, 31, 2, 7, 21, -19, 7, -22, -27, -54, 13, -4, -28, -11, -58, 28, -15, 21, -27, -37, 9, 7, 55, 26, 23, 2, -28, -7, 22, -41, -34, 37, 43, -8, -13, -13, -5, 40, -63, 1, 29, -51, 45, 
  -20, 59, -41, -14, -50, 56, 9, -56, 48, -47, 38, -33, -43, -26, -33, -6, -1, -48, 4, -17, -19, -48, -58, -12, -10, -52, 42, 18, 22, 42, -53, 50, -53, -31, 6, 19, -59, 13, 26, 21, 7, -54, 38, -40, -40, 46, 26, 47, 13, 2, 55, 19, -28, 55, 24, 7, 0, 53, -19, -35, -9, 30, 18, 45, -54, 19, 25, -41, 38, -36, -57, 51, -20, 58, 21, 29, 9, 4, 49, 47, 43, 52, -6, -5, -35, 19, 41, -49, -46, 55, -54, -50, -59, -55, -44, -37, -60, -45, -39, 
  25, 18, 22, -52, 43, 34, -13, -6, 31, -42, -54, 63, 2, -16, -55, -31, 17, -4, 50, 6, -1, -11, -5, -30, -28, 59, -46, 20, 53, 4, -16, 28, -21, 30, 40, 22, -4, 13, -46, 20, 36, -44, -37, 46, -10, -4, 47, 35, -36, 57, -54, -39, 19, -36, -12, 6, -45, 24, 41, 23, -4, 50, -26, 65, 57, 59, -52, 2, -3, -54, 30, -33, 34, 67, -35, 63, 34, 38, 51, -15, -22, -9, 48, -14, 36, 1, 33, 28, 30, -3, 42, -4, -50, -8, 11, 31, -6, -47, 63, 
  -3, 12, 6, 30, -52, -3, -5, -23, 30, -11, 2, -19, -29, -3, 5, -26, 16, 53, 49, -49, 38, -38, -4, 51, 46, -45, -21, -38, 52, 34, -47, 18, -2, -45, -9, 51, -7, 44, -3, 44, -43, -26, 31, 35, 17, -47, 40, -6, -19, 43, -15, 60, -36, 59, 43, -57, -47, -24, 33, 17, -34, -21, 57, -39, 54, 50, 56, -34, 44, 26, 6, -25, -31, 11, 25, 1, 39, 40, 25, -38, -1, -48, -24, 18, -59, 29, -16, -22, 17, 5, -51, 16, 34, -43, -32, -11, 5, -42, -29, 
  -48, -50, -57, -45, 57, -20, 19, -2, 8, 41, 5, 51, 11, 51, -7, -44, -38, 37, -19, -6, -33, 3, 38, -54, -26, 19, -44, 34, 21, -50, 58, -11, -56, -1, 53, 22, -22, 7, -39, -6, -24, 3, 48, 52, 20, 39, 12, 36, -25, -56, 55, -29, -48, 1, 36, -38, 8, 50, -58, 56, -34, 11, 35, -53, -44, -30, 49, -16, -59, -31, -25, -9, -34, -31, 18, -28, -48, -52, 31, 39, 42, 54, -33, -49, -43, 32, 32, -34, 26, 40, 40, -11, 18, -4, 12, -34, 50, -5, 49, 
  50, 33, -3, -11, 6, 59, 15, 42, 46, 56, -13, 50, 8, -41, -36, 26, 8, 35, 46, 44, 30, -23, -2, 14, 42, -42, -13, 48, -38, 37, -53, 24, -40, -22, 43, -47, 48, 29, 49, -26, -25, -18, -60, -54, -51, -7, -60, 0, -3, 9, -15, -6, 49, 60, 58, -30, 47, 24, -56, 26, -15, -8, 38, 7, 5, 38, 44, -35, 21, 29, -41, -30, 1, 58, -20, 15, -39, 22, -33, -12, -46, -21, 25, 50, 14, -18, 43, 59, -26, -47, -3, 46, 18, -40, -53, -48, -4, 32, -13, 
  17, 48, 13, -39, 41, -25, 11, -31, -14, 50, -10, -33, -35, 40, 49, -63, 26, -8, -62, -17, -61, -17, 49, -15, -46, -11, -49, 13, 43, -30, 36, -24, -23, 46, -51, -35, -36, -11, -50, 51, -18, 9, 6, 42, -11, -16, 37, -30, -14, 20, -23, -26, -24, -52, 43, 36, 35, -1, 31, 20, -50, -39, 16, -12, -20, 33, 46, 54, 56, -55, -64, -55, 10, -13, -57, 35, -6, 15, -29, 29, 0, -10, 48, -12, -39, 33, -43, -17, -14, -24, 54, 24, -51, 7, -1, 45, -66, 27, -56, 
  3, 18, -16, 37, 5, -18, 27, -14, 16, 43, 56, 46, 16, -19, -2, 8, -41, -37, 11, 43, -65, -29, 19, -34, -49, 44, 29, 7, 48, -31, -63, 57, 14, 23, 40, 32, 50, -39, 31, -60, -23, -8, 36, -21, -41, 23, -31, -8, -5, 53, -43, -41, -10, -17, 35, 29, 12, 57, -59, -30, -6, -2, 54, -13, -4, 35, 14, 53, -60, 48, 42, -52, -5, 16, 50, -49, 16, 5, -17, 73, 9, -39, 25, -18, 27, 22, 29, -44, -50, 35, -6, 32, -46, -18, 20, -14, 28, 29, 33, 
  4, -100, 77, 2, 62, 16, 70, 77, 49, 21, -9, -16, -122, 46, 25, 8, -19, -17, -16, -28, 19, 28, -29, -24, 80, 28, -22, 23, -4, 27, 31, 17, 65, 48, 21, -11, 43, 32, -16, 2, 24, -24, 66, -32, -6, 39, 65, -29, 72, 34, -17, 33, 64, 60, 19, -26, 38, 44, 67, 71, -34, 62, 11, 8, -32, 28, 53, 127, -85, -24, 70, 25, 76, 25, 16, 52, 70, -55, -9, 56, 31, -67, -44, -1, -63, 3, -51, -16, -57, -97, 5, 81, 49, -34, 38, -3, -52, -10, -9, 
  -43, 64, -19, 16, -20, 47, -42, -35, -14, 43, -41, 23, -21, -23, 54, -51, -10, 36, 32, 36, 9, -32, 9, -51, -24, -22, 31, 17, 1, 1, -60, -54, -57, 30, 41, -22, -21, 33, -8, 40, 46, -40, 43, -12, -30, 45, -57, 52, -27, 35, -13, 28, 9, 15, 6, 28, -13, -27, -14, -54, 30, -37, -50, -27, -9, 24, -40, -49, -51, -23, 43, -16, 9, -37, -31, 39, -32, -30, -43, 65, 6, 52, 33, -37, -23, -61, -34, 25, 25, 49, -43, -10, -4, -29, 22, -8, -62, -32, -10, 
  -42, 48, 34, 13, 1, 3, -4, -26, -5, 21, 5, -44, -25, -57, -35, 33, 46, 34, -46, -2, -23, -49, -22, 56, 27, 26, -9, 10, 63, 59, 7, -7, -3, 42, 17, 14, -2, -16, -44, 27, 19, 62, -31, -41, 32, 0, 28, 46, 61, 19, 57, 51, -7, 21, -11, 14, -49, -9, 7, -23, -23, -17, -10, 60, -11, -16, -3, 10, 1, 63, -19, -42, 44, -4, 19, -51, 54, 22, 29, 48, 35, 65, 30, -50, 28, 37, 9, -34, 31, 3, -62, 54, 57, 39, -27, -23, 58, 47, 69, 
  -30, 4, -55, -55, 50, -28, 7, 40, -37, 2, 2, 22, 13, -19, -13, -21, -1, -14, -36, 44, -59, -21, 30, -54, 55, -11, -46, 55, 32, 28, 32, 7, 7, 11, -53, -58, 52, 7, -52, 8, -50, 35, -49, 43, 52, 55, 34, 49, 3, -47, -29, 36, -31, 51, 53, -44, -6, -21, 20, -53, 42, -19, 36, 43, 48, -22, -26, -19, -5, 9, 41, 37, -62, -58, 25, 42, -55, -25, 34, -55, 37, -64, -30, -64, 38, -7, 49, -57, -32, -39, 9, -49, -52, 45, 56, -36, 35, -47, 31, 
  -41, -13, 48, 53, 36, 23, -1, -41, -16, -15, -51, -41, 45, -6, -26, 42, -24, -10, -50, -10, 38, -52, -18, 59, -39, -51, 45, -16, 12, -4, 34, 23, 49, 6, 26, 39, 26, -8, 14, 36, -21, -59, 17, -24, 57, 47, -46, 27, 32, 5, 5, -51, -43, -27, 23, -43, 8, 24, -57, 18, 6, -15, 59, -49, 45, 22, -46, 54, -43, 34, 20, -32, -3, -50, 54, -37, -34, -35, 33, -33, -46, 32, -27, -55, -59, -31, 2, 14, -29, 11, -32, 55, 13, -30, 12, 52, 8, 59, -11, 
  -19, 31, 41, 29, 12, -3, -1, -54, 51, 52, -17, 52, 31, -39, 53, 23, 17, -52, 21, -4, -14, 39, 57, -35, 22, 58, 1, 56, -52, -58, -55, -41, 63, 36, 24, 1, 49, -27, 33, -12, -45, -23, 58, 25, -31, -20, -10, 44, -26, -60, 53, 43, -18, -17, -20, 7, 40, -56, 11, -20, 17, -42, 19, -43, -32, 51, 60, 22, 12, -35, 46, -35, 6, -22, -52, 39, 34, 27, -19, 31, 5, 59, -4, 21, -41, 70, 6, 61, -47, 58, -22, 2, 33, -48, 40, 55, 22, 65, 68, 
};
const TfArray<2, int> tensor_dimension1 = { 2, { 20,99 } };
const TfArray<1, float> quant1_scale = { 1, { 0.0036831395700573921, } };
const TfArray<1, int> quant1_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant1 = { (TfLiteFloatArray*)&quant1_scale, (TfLiteIntArray*)&quant1_zero, 0 };
const ALIGN(16) int32_t tensor_data2[20] = { 6, 0, 6, 0, 17, -9, -2, 0, 6, 0, 0, 0, -5, -4, 30, -5, 3, -3, 0, 1, };
const TfArray<1, int> tensor_dimension2 = { 1, { 20 } };
const TfArray<1, float> quant2_scale = { 1, { 0.0035177981480956078, } };
const TfArray<1, int> quant2_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant2 = { (TfLiteFloatArray*)&quant2_scale, (TfLiteIntArray*)&quant2_zero, 0 };
const ALIGN(16) int8_t tensor_data3[10*20] = { 
  -65, -3, 33, 18, 89, -61, -26, 19, -87, -97, -34, -59, 99, 89, -30, 4, -90, 17, -32, 16, 
  -69, 15, -54, 41, 26, 9, 74, -47, -38, -77, 17, -82, -25, -32, -82, -92, -44, 70, 51, -91, 
  -67, 73, 39, -54, 85, 11, 57, -47, 98, 81, -62, -48, 46, -86, 52, -19, -11, 102, -94, -18, 
  -74, -19, -69, -87, -12, 45, 64, 80, 89, -78, 82, 41, -2, -72, -22, 100, 19, 27, 28, -75, 
  11, 7, -62, -81, -106, 87, -42, -6, -67, 104, 5, -104, -96, 34, -17, 16, 15, -93, 103, 21, 
  64, 86, -85, 9, -73, -21, 3, -24, 100, -100, -109, 101, -82, 49, -54, 84, -92, -9, -92, 75, 
  81, -33, 16, 84, 84, -37, 5, 49, 37, 91, -52, 63, -109, -12, 28, -26, 44, -8, 39, -47, 
  -58, 95, -59, -101, -22, -17, -31, -86, 92, 70, 68, 98, -19, -5, -24, -41, -61, 17, -44, 47, 
  -79, 69, 3, 49, 114, -9, 56, -102, -28, -77, 44, 78, 89, 101, 3, 45, -89, 95, -1, -1, 
  -24, 34, 26, 82, -104, 68, 79, -59, 86, -37, -21, 32, -85, -31, -127, 28, 108, 101, -35, 103, 
};
const TfArray<2, int> tensor_dimension3 = { 2, { 10,20 } };
const TfArray<1, float> quant3_scale = { 1, { 0.0040412186644971371, } };
const TfArray<1, int> quant3_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant3 = { (TfLiteFloatArray*)&quant3_scale, (TfLiteIntArray*)&quant3_zero, 0 };
const ALIGN(16) int32_t tensor_data4[10] = { 13, 0, 52, -17, -19, 0, 64, 0, -11, 9, };
const TfArray<1, int> tensor_dimension4 = { 1, { 10 } };
const TfArray<1, float> quant4_scale = { 1, { 0.00096200645202770829, } };
const TfArray<1, int> quant4_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant4 = { (TfLiteFloatArray*)&quant4_scale, (TfLiteIntArray*)&quant4_zero, 0 };
const ALIGN(16) int8_t tensor_data5[5*10] = { 
  -37, -11, -79, -5, -30, 80, -21, -113, 39, -49, 
  69, -105, 59, 4, 34, 22, -127, 31, -97, 37, 
  -120, 98, 76, 25, 42, -14, 39, 107, 107, -69, 
  -106, 7, 39, 44, -10, 12, 54, -91, -84, -85, 
  -10, 96, 60, -3, -86, -55, 21, 107, -33, -107, 
};
const TfArray<2, int> tensor_dimension5 = { 2, { 5,10 } };
const TfArray<1, float> quant5_scale = { 1, { 0.0053166821599006653, } };
const TfArray<1, int> quant5_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant5 = { (TfLiteFloatArray*)&quant5_scale, (TfLiteIntArray*)&quant5_zero, 0 };
const ALIGN(16) int32_t tensor_data6[5] = { -15, -30, -14, -105, -95, };
const TfArray<1, int> tensor_dimension6 = { 1, { 5 } };
const TfArray<1, float> quant6_scale = { 1, { 0.00071467179805040359, } };
const TfArray<1, int> quant6_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant6 = { (TfLiteFloatArray*)&quant6_scale, (TfLiteIntArray*)&quant6_zero, 0 };
const ALIGN(8) int8_t tensor_data7[2*5] = { 
  42, -100, 101, -35, -108, 
  -52, 76, -127, 103, -7, 
};
const TfArray<2, int> tensor_dimension7 = { 2, { 2,5 } };
const TfArray<1, float> quant7_scale = { 1, { 0.0058962339535355568, } };
const TfArray<1, int> quant7_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant7 = { (TfLiteFloatArray*)&quant7_scale, (TfLiteIntArray*)&quant7_zero, 0 };
const ALIGN(8) int32_t tensor_data8[2] = { 657, -657, };
const TfArray<1, int> tensor_dimension8 = { 1, { 2 } };
const TfArray<1, float> quant8_scale = { 1, { 0.00037056457949802279, } };
const TfArray<1, int> quant8_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant8 = { (TfLiteFloatArray*)&quant8_scale, (TfLiteIntArray*)&quant8_zero, 0 };
const TfArray<2, int> tensor_dimension9 = { 2, { 1,20 } };
const TfArray<1, float> quant9_scale = { 1, { 0.23804859817028046, } };
const TfArray<1, int> quant9_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant9 = { (TfLiteFloatArray*)&quant9_scale, (TfLiteIntArray*)&quant9_zero, 0 };
const TfArray<2, int> tensor_dimension10 = { 2, { 1,10 } };
const TfArray<1, float> quant10_scale = { 1, { 0.13442063331604004, } };
const TfArray<1, int> quant10_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant10 = { (TfLiteFloatArray*)&quant10_scale, (TfLiteIntArray*)&quant10_zero, 0 };
const TfArray<2, int> tensor_dimension11 = { 2, { 1,5 } };
const TfArray<1, float> quant11_scale = { 1, { 0.062847673892974854, } };
const TfArray<1, int> quant11_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant11 = { (TfLiteFloatArray*)&quant11_scale, (TfLiteIntArray*)&quant11_zero, 0 };
const TfArray<2, int> tensor_dimension12 = { 2, { 1,2 } };
const TfArray<1, float> quant12_scale = { 1, { 0.06310533732175827, } };
const TfArray<1, int> quant12_zero = { 1, { 31 } };
const TfLiteAffineQuantization quant12 = { (TfLiteFloatArray*)&quant12_scale, (TfLiteIntArray*)&quant12_zero, 0 };
const TfArray<2, int> tensor_dimension13 = { 2, { 1,2 } };
const TfArray<1, float> quant13_scale = { 1, { 0.00390625, } };
const TfArray<1, int> quant13_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant13 = { (TfLiteFloatArray*)&quant13_scale, (TfLiteIntArray*)&quant13_zero, 0 };
const TfLiteFullyConnectedParams opdata0 = { kTfLiteActRelu, kTfLiteFullyConnectedWeightsFormatDefault, false, false };
const TfArray<3, int> inputs0 = { 3, { 0,1,2 } };
const TfArray<1, int> outputs0 = { 1, { 9 } };
const TfLiteFullyConnectedParams opdata1 = { kTfLiteActRelu, kTfLiteFullyConnectedWeightsFormatDefault, false, false };
const TfArray<3, int> inputs1 = { 3, { 9,3,4 } };
const TfArray<1, int> outputs1 = { 1, { 10 } };
const TfLiteFullyConnectedParams opdata2 = { kTfLiteActRelu, kTfLiteFullyConnectedWeightsFormatDefault, false, false };
const TfArray<3, int> inputs2 = { 3, { 10,5,6 } };
const TfArray<1, int> outputs2 = { 1, { 11 } };
const TfLiteFullyConnectedParams opdata3 = { kTfLiteActNone, kTfLiteFullyConnectedWeightsFormatDefault, false, false };
const TfArray<3, int> inputs3 = { 3, { 11,7,8 } };
const TfArray<1, int> outputs3 = { 1, { 12 } };
const TfLiteSoftmaxParams opdata4 = { 1 };
const TfArray<1, int> inputs4 = { 1, { 12 } };
const TfArray<1, int> outputs4 = { 1, { 13 } };
const TensorInfo_t tensorData[] = {
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension0, 99, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant0))}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data1, (TfLiteIntArray*)&tensor_dimension1, 1980, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant1))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data2, (TfLiteIntArray*)&tensor_dimension2, 80, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant2))}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data3, (TfLiteIntArray*)&tensor_dimension3, 200, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant3))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data4, (TfLiteIntArray*)&tensor_dimension4, 40, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant4))}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data5, (TfLiteIntArray*)&tensor_dimension5, 50, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant5))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data6, (TfLiteIntArray*)&tensor_dimension6, 20, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant6))}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data7, (TfLiteIntArray*)&tensor_dimension7, 10, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant7))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data8, (TfLiteIntArray*)&tensor_dimension8, 8, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant8))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 112, (TfLiteIntArray*)&tensor_dimension9, 20, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant9))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 16, (TfLiteIntArray*)&tensor_dimension10, 10, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant10))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension11, 5, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant11))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 16, (TfLiteIntArray*)&tensor_dimension12, 2, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant12))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension13, 2, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant13))}, },
};const NodeInfo_t nodeData[] = {
  { (TfLiteIntArray*)&inputs0, (TfLiteIntArray*)&outputs0, const_cast<void*>(static_cast<const void*>(&opdata0)), OP_FULLY_CONNECTED, },
  { (TfLiteIntArray*)&inputs1, (TfLiteIntArray*)&outputs1, const_cast<void*>(static_cast<const void*>(&opdata1)), OP_FULLY_CONNECTED, },
  { (TfLiteIntArray*)&inputs2, (TfLiteIntArray*)&outputs2, const_cast<void*>(static_cast<const void*>(&opdata2)), OP_FULLY_CONNECTED, },
  { (TfLiteIntArray*)&inputs3, (TfLiteIntArray*)&outputs3, const_cast<void*>(static_cast<const void*>(&opdata3)), OP_FULLY_CONNECTED, },
  { (TfLiteIntArray*)&inputs4, (TfLiteIntArray*)&outputs4, const_cast<void*>(static_cast<const void*>(&opdata4)), OP_SOFTMAX, },
};
static void* overflow_buffers[EI_MAX_OVERFLOW_BUFFER_COUNT];
static size_t overflow_buffers_ix = 0;
static void * AllocatePersistentBuffer(struct TfLiteContext* ctx,
                                       size_t bytes) {
  void *ptr;
  if (current_location - bytes < tensor_boundary) {
    if (overflow_buffers_ix > EI_MAX_OVERFLOW_BUFFER_COUNT - 1) {
      ei_printf("ERR: Failed to allocate persistent buffer of size %d, does not fit in tensor arena and reached EI_MAX_OVERFLOW_BUFFER_COUNT\n",
        (int)bytes);
      return NULL;
    }

    // OK, this will look super weird, but.... we have CMSIS-NN buffers which
    // we cannot calculate beforehand easily.
    ptr = ei_calloc(bytes, 1);
    if (ptr == NULL) {
      ei_printf("ERR: Failed to allocate persistent buffer of size %d\n", (int)bytes);
      return NULL;
    }
    overflow_buffers[overflow_buffers_ix++] = ptr;
    return ptr;
  }

  current_location -= bytes;

  ptr = current_location;
  memset(ptr, 0, bytes);

  return ptr;
}
typedef struct {
  size_t bytes;
  void *ptr;
} scratch_buffer_t;
static scratch_buffer_t scratch_buffers[EI_MAX_SCRATCH_BUFFER_COUNT];
static size_t scratch_buffers_ix = 0;

static TfLiteStatus RequestScratchBufferInArena(struct TfLiteContext* ctx, size_t bytes,
                                                int* buffer_idx) {
  if (scratch_buffers_ix > EI_MAX_SCRATCH_BUFFER_COUNT - 1) {
    ei_printf("ERR: Failed to allocate scratch buffer of size %d, reached EI_MAX_SCRATCH_BUFFER_COUNT\n",
      (int)bytes);
    return kTfLiteError;
  }

  scratch_buffer_t b;
  b.bytes = bytes;

  b.ptr = AllocatePersistentBuffer(ctx, b.bytes);
  if (!b.ptr) {
    ei_printf("ERR: Failed to allocate scratch buffer of size %d\n",
      (int)bytes);
    return kTfLiteError;
  }

  scratch_buffers[scratch_buffers_ix] = b;
  *buffer_idx = scratch_buffers_ix;

  scratch_buffers_ix++;

  return kTfLiteOk;
}

static void* GetScratchBuffer(struct TfLiteContext* ctx, int buffer_idx) {
  if (buffer_idx > (int)scratch_buffers_ix) {
    return NULL;
  }
  return scratch_buffers[buffer_idx].ptr;
}

static TfLiteTensor* GetTensor(const struct TfLiteContext* context,
                               int tensor_idx) {
  return &tflTensors[tensor_idx];
}

static TfLiteEvalTensor* GetEvalTensor(const struct TfLiteContext* context,
                                       int tensor_idx) {
  return &tflEvalTensors[tensor_idx];
}

} // namespace

TfLiteStatus trained_model_init( void*(*alloc_fnc)(size_t,size_t) ) {
#ifdef EI_CLASSIFIER_ALLOCATION_HEAP
  tensor_arena = (uint8_t*) alloc_fnc(16, kTensorArenaSize);
  if (!tensor_arena) {
    ei_printf("ERR: failed to allocate tensor arena\n");
    return kTfLiteError;
  }
#else
  memset(tensor_arena, 0, kTensorArenaSize);
#endif
  tensor_boundary = tensor_arena;
  current_location = tensor_arena + kTensorArenaSize;
  ctx.AllocatePersistentBuffer = &AllocatePersistentBuffer;
  ctx.RequestScratchBufferInArena = &RequestScratchBufferInArena;
  ctx.GetScratchBuffer = &GetScratchBuffer;
  ctx.GetTensor = &GetTensor;
  ctx.GetEvalTensor = &GetEvalTensor;
  ctx.tensors = tflTensors;
  ctx.tensors_size = 14;
  for (size_t i = 0; i < 14; ++i) {
    tflTensors[i].type = tensorData[i].type;
    tflEvalTensors[i].type = tensorData[i].type;
    tflTensors[i].is_variable = 0;

#if defined(EI_CLASSIFIER_ALLOCATION_HEAP)
    tflTensors[i].allocation_type = tensorData[i].allocation_type;
#else
    tflTensors[i].allocation_type = (tensor_arena <= tensorData[i].data && tensorData[i].data < tensor_arena + kTensorArenaSize) ? kTfLiteArenaRw : kTfLiteMmapRo;
#endif
    tflTensors[i].bytes = tensorData[i].bytes;
    tflTensors[i].dims = tensorData[i].dims;
    tflEvalTensors[i].dims = tensorData[i].dims;

#if defined(EI_CLASSIFIER_ALLOCATION_HEAP)
    if(tflTensors[i].allocation_type == kTfLiteArenaRw){
      uint8_t* start = (uint8_t*) ((uintptr_t)tensorData[i].data + (uintptr_t) tensor_arena);

     tflTensors[i].data.data =  start;
     tflEvalTensors[i].data.data =  start;
    }
    else {
       tflTensors[i].data.data = tensorData[i].data;
       tflEvalTensors[i].data.data = tensorData[i].data;
    }
#else
    tflTensors[i].data.data = tensorData[i].data;
    tflEvalTensors[i].data.data = tensorData[i].data;
#endif // EI_CLASSIFIER_ALLOCATION_HEAP
    tflTensors[i].quantization = tensorData[i].quantization;
    if (tflTensors[i].quantization.type == kTfLiteAffineQuantization) {
      TfLiteAffineQuantization const* quant = ((TfLiteAffineQuantization const*)(tensorData[i].quantization.params));
      tflTensors[i].params.scale = quant->scale->data[0];
      tflTensors[i].params.zero_point = quant->zero_point->data[0];
    }
    if (tflTensors[i].allocation_type == kTfLiteArenaRw) {
      auto data_end_ptr = (uint8_t*)tflTensors[i].data.data + tensorData[i].bytes;
      if (data_end_ptr > tensor_boundary) {
        tensor_boundary = data_end_ptr;
      }
    }
  }
  if (tensor_boundary > current_location /* end of arena size */) {
    ei_printf("ERR: tensor arena is too small, does not fit model - even without scratch buffers\n");
    return kTfLiteError;
  }
  registrations[OP_FULLY_CONNECTED] = Register_FULLY_CONNECTED();
  registrations[OP_SOFTMAX] = Register_SOFTMAX();

  for (size_t i = 0; i < 5; ++i) {
    tflNodes[i].inputs = nodeData[i].inputs;
    tflNodes[i].outputs = nodeData[i].outputs;
    tflNodes[i].builtin_data = nodeData[i].builtin_data;
tflNodes[i].custom_initial_data = nullptr;
      tflNodes[i].custom_initial_data_size = 0;
if (registrations[nodeData[i].used_op_index].init) {
      tflNodes[i].user_data = registrations[nodeData[i].used_op_index].init(&ctx, (const char*)tflNodes[i].builtin_data, 0);
    }
  }
  for (size_t i = 0; i < 5; ++i) {
    if (registrations[nodeData[i].used_op_index].prepare) {
      TfLiteStatus status = registrations[nodeData[i].used_op_index].prepare(&ctx, &tflNodes[i]);
      if (status != kTfLiteOk) {
        return status;
      }
    }
  }
  return kTfLiteOk;
}

static const int inTensorIndices[] = {
  0, 
};
TfLiteTensor* trained_model_input(int index) {
  return &ctx.tensors[inTensorIndices[index]];
}

static const int outTensorIndices[] = {
  13, 
};
TfLiteTensor* trained_model_output(int index) {
  return &ctx.tensors[outTensorIndices[index]];
}

TfLiteStatus trained_model_invoke() {
  for (size_t i = 0; i < 5; ++i) {
    TfLiteStatus status = registrations[nodeData[i].used_op_index].invoke(&ctx, &tflNodes[i]);

#if EI_CLASSIFIER_PRINT_STATE
    ei_printf("layer %lu\n", i);
    ei_printf("    inputs:\n");
    for (size_t ix = 0; ix < tflNodes[i].inputs->size; ix++) {
      auto d = tensorData[tflNodes[i].inputs->data[ix]];

      size_t data_ptr = (size_t)d.data;

      if (d.allocation_type == kTfLiteArenaRw) {
        data_ptr = (size_t)tensor_arena + data_ptr;
      }

      if (d.type == TfLiteType::kTfLiteInt8) {
        int8_t* data = (int8_t*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes; jx++) {
          ei_printf("%d ", data[jx]);
        }
      }
      else {
        float* data = (float*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes / 4; jx++) {
          ei_printf("%f ", data[jx]);
        }
      }
      ei_printf("\n");
    }
    ei_printf("\n");

    ei_printf("    outputs:\n");
    for (size_t ix = 0; ix < tflNodes[i].outputs->size; ix++) {
      auto d = tensorData[tflNodes[i].outputs->data[ix]];

      size_t data_ptr = (size_t)d.data;

      if (d.allocation_type == kTfLiteArenaRw) {
        data_ptr = (size_t)tensor_arena + data_ptr;
      }

      if (d.type == TfLiteType::kTfLiteInt8) {
        int8_t* data = (int8_t*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes; jx++) {
          ei_printf("%d ", data[jx]);
        }
      }
      else {
        float* data = (float*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes / 4; jx++) {
          ei_printf("%f ", data[jx]);
        }
      }
      ei_printf("\n");
    }
    ei_printf("\n");
#endif // EI_CLASSIFIER_PRINT_STATE

    if (status != kTfLiteOk) {
      return status;
    }
  }
  return kTfLiteOk;
}

TfLiteStatus trained_model_reset( void (*free_fnc)(void* ptr) ) {
#ifdef EI_CLASSIFIER_ALLOCATION_HEAP
  free_fnc(tensor_arena);
#endif

  // scratch buffers are allocated within the arena, so just reset the counter so memory can be reused
  scratch_buffers_ix = 0;

  // overflow buffers are on the heap, so free them first
  for (size_t ix = 0; ix < overflow_buffers_ix; ix++) {
    ei_free(overflow_buffers[ix]);
  }
  overflow_buffers_ix = 0;
  return kTfLiteOk;
}