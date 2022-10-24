// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// RUN: %clang_cc1 -triple aarch64-none-linux-gnu -target-feature +sve \
// RUN: -disable-O0-optnone -mvscale-min=4 -mvscale-max=4 \
// RUN:  -emit-llvm -o - %s | opt -S -sroa | FileCheck %s

// REQUIRES: aarch64-registered-target

#include <arm_sve.h>
#include <stddef.h>

#define N 512

typedef svint8_t fixed_int8_t __attribute__((arm_sve_vector_bits(N)));
typedef svint16_t fixed_int16_t __attribute__((arm_sve_vector_bits(N)));
typedef svint32_t fixed_int32_t __attribute__((arm_sve_vector_bits(N)));
typedef svint64_t fixed_int64_t __attribute__((arm_sve_vector_bits(N)));

typedef svuint8_t fixed_uint8_t __attribute__((arm_sve_vector_bits(N)));
typedef svuint16_t fixed_uint16_t __attribute__((arm_sve_vector_bits(N)));
typedef svuint32_t fixed_uint32_t __attribute__((arm_sve_vector_bits(N)));
typedef svuint64_t fixed_uint64_t __attribute__((arm_sve_vector_bits(N)));

typedef svfloat16_t fixed_float16_t __attribute__((arm_sve_vector_bits(N)));
typedef svfloat32_t fixed_float32_t __attribute__((arm_sve_vector_bits(N)));
typedef svfloat64_t fixed_float64_t __attribute__((arm_sve_vector_bits(N)));

typedef svbool_t fixed_bool_t __attribute__((arm_sve_vector_bits(N)));

// CHECK-LABEL: @subscript_int16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[A:%.*]] = call <32 x i16> @llvm.vector.extract.v32i16.nxv8i16(<vscale x 8 x i16> [[A_COERCE:%.*]], i64 0)
// CHECK-NEXT:    [[VECEXT:%.*]] = extractelement <32 x i16> [[A]], i64 [[B:%.*]]
// CHECK-NEXT:    ret i16 [[VECEXT]]
//
int16_t subscript_int16(fixed_int16_t a, size_t b) {
  return a[b];
}

// CHECK-LABEL: @subscript_uint16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[A:%.*]] = call <32 x i16> @llvm.vector.extract.v32i16.nxv8i16(<vscale x 8 x i16> [[A_COERCE:%.*]], i64 0)
// CHECK-NEXT:    [[VECEXT:%.*]] = extractelement <32 x i16> [[A]], i64 [[B:%.*]]
// CHECK-NEXT:    ret i16 [[VECEXT]]
//
uint16_t subscript_uint16(fixed_uint16_t a, size_t b) {
  return a[b];
}

// CHECK-LABEL: @subscript_int32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[A:%.*]] = call <16 x i32> @llvm.vector.extract.v16i32.nxv4i32(<vscale x 4 x i32> [[A_COERCE:%.*]], i64 0)
// CHECK-NEXT:    [[VECEXT:%.*]] = extractelement <16 x i32> [[A]], i64 [[B:%.*]]
// CHECK-NEXT:    ret i32 [[VECEXT]]
//
int32_t subscript_int32(fixed_int32_t a, size_t b) {
  return a[b];
}

// CHECK-LABEL: @subscript_uint32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[A:%.*]] = call <16 x i32> @llvm.vector.extract.v16i32.nxv4i32(<vscale x 4 x i32> [[A_COERCE:%.*]], i64 0)
// CHECK-NEXT:    [[VECEXT:%.*]] = extractelement <16 x i32> [[A]], i64 [[B:%.*]]
// CHECK-NEXT:    ret i32 [[VECEXT]]
//
uint32_t subscript_uint32(fixed_uint32_t a, size_t b) {
  return a[b];
}

// CHECK-LABEL: @subscript_int64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[A:%.*]] = call <8 x i64> @llvm.vector.extract.v8i64.nxv2i64(<vscale x 2 x i64> [[A_COERCE:%.*]], i64 0)
// CHECK-NEXT:    [[VECEXT:%.*]] = extractelement <8 x i64> [[A]], i64 [[B:%.*]]
// CHECK-NEXT:    ret i64 [[VECEXT]]
//
int64_t subscript_int64(fixed_int64_t a, size_t b) {
  return a[b];
}

// CHECK-LABEL: @subscript_uint64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[A:%.*]] = call <8 x i64> @llvm.vector.extract.v8i64.nxv2i64(<vscale x 2 x i64> [[A_COERCE:%.*]], i64 0)
// CHECK-NEXT:    [[VECEXT:%.*]] = extractelement <8 x i64> [[A]], i64 [[B:%.*]]
// CHECK-NEXT:    ret i64 [[VECEXT]]
//
uint64_t subscript_uint64(fixed_uint64_t a, size_t b) {
  return a[b];
}

// CHECK-LABEL: @subscript_float16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[A:%.*]] = call <32 x half> @llvm.vector.extract.v32f16.nxv8f16(<vscale x 8 x half> [[A_COERCE:%.*]], i64 0)
// CHECK-NEXT:    [[VECEXT:%.*]] = extractelement <32 x half> [[A]], i64 [[B:%.*]]
// CHECK-NEXT:    ret half [[VECEXT]]
//
__fp16 subscript_float16(fixed_float16_t a, size_t b) {
  return a[b];
}

// CHECK-LABEL: @subscript_float32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[A:%.*]] = call <16 x float> @llvm.vector.extract.v16f32.nxv4f32(<vscale x 4 x float> [[A_COERCE:%.*]], i64 0)
// CHECK-NEXT:    [[VECEXT:%.*]] = extractelement <16 x float> [[A]], i64 [[B:%.*]]
// CHECK-NEXT:    ret float [[VECEXT]]
//
float subscript_float32(fixed_float32_t a, size_t b) {
  return a[b];
}

// CHECK-LABEL: @subscript_float64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[A:%.*]] = call <8 x double> @llvm.vector.extract.v8f64.nxv2f64(<vscale x 2 x double> [[A_COERCE:%.*]], i64 0)
// CHECK-NEXT:    [[VECEXT:%.*]] = extractelement <8 x double> [[A]], i64 [[B:%.*]]
// CHECK-NEXT:    ret double [[VECEXT]]
//
double subscript_float64(fixed_float64_t a, size_t b) {
  return a[b];
}
