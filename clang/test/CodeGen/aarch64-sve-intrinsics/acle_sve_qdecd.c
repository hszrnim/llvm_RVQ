// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// REQUIRES: aarch64-registered-target
// RUN: %clang_cc1 -triple aarch64-none-linux-gnu -target-feature +sve -S -disable-O0-optnone -Werror -Wall -emit-llvm -o - %s | opt -S -mem2reg -instcombine -tailcallelim | FileCheck %s
// RUN: %clang_cc1 -triple aarch64-none-linux-gnu -target-feature +sve -S -disable-O0-optnone -Werror -Wall -emit-llvm -o - -x c++ %s | opt -S -mem2reg -instcombine -tailcallelim | FileCheck %s -check-prefix=CPP-CHECK
// RUN: %clang_cc1 -DSVE_OVERLOADED_FORMS -triple aarch64-none-linux-gnu -target-feature +sve -S -disable-O0-optnone -Werror -Wall -emit-llvm -o - %s | opt -S -mem2reg -instcombine -tailcallelim | FileCheck %s
// RUN: %clang_cc1 -DSVE_OVERLOADED_FORMS -triple aarch64-none-linux-gnu -target-feature +sve -S -disable-O0-optnone -Werror -Wall -emit-llvm -o - -x c++ %s | opt -S -mem2reg -instcombine -tailcallelim | FileCheck %s -check-prefix=CPP-CHECK
// RUN: %clang_cc1 -triple aarch64-none-linux-gnu -target-feature +sve -S -disable-O0-optnone -Werror -Wall -o /dev/null %s
#include <arm_sve.h>

#ifdef SVE_OVERLOADED_FORMS
// A simple used,unused... macro, long enough to represent any SVE builtin.
#define SVE_ACLE_FUNC(A1,A2_UNUSED,A3,A4_UNUSED) A1##A3
#else
#define SVE_ACLE_FUNC(A1,A2,A3,A4) A1##A2##A3##A4
#endif

// CHECK-LABEL: @test_svqdecd_n_s32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call i32 @llvm.aarch64.sve.sqdecd.n32(i32 [[OP:%.*]], i32 31, i32 1)
// CHECK-NEXT:    ret i32 [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z18test_svqdecd_n_s32i(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call i32 @llvm.aarch64.sve.sqdecd.n32(i32 [[OP:%.*]], i32 31, i32 1)
// CPP-CHECK-NEXT:    ret i32 [[TMP0]]
//
int32_t test_svqdecd_n_s32(int32_t op)
{
  return SVE_ACLE_FUNC(svqdecd,_n_s32,,)(op, 1);
}

// CHECK-LABEL: @test_svqdecd_n_s32_1(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call i32 @llvm.aarch64.sve.sqdecd.n32(i32 [[OP:%.*]], i32 31, i32 16)
// CHECK-NEXT:    ret i32 [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z20test_svqdecd_n_s32_1i(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call i32 @llvm.aarch64.sve.sqdecd.n32(i32 [[OP:%.*]], i32 31, i32 16)
// CPP-CHECK-NEXT:    ret i32 [[TMP0]]
//
int32_t test_svqdecd_n_s32_1(int32_t op)
{
  return SVE_ACLE_FUNC(svqdecd,_n_s32,,)(op, 16);
}

// CHECK-LABEL: @test_svqdecd_n_s64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call i64 @llvm.aarch64.sve.sqdecd.n64(i64 [[OP:%.*]], i32 31, i32 1)
// CHECK-NEXT:    ret i64 [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z18test_svqdecd_n_s64l(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call i64 @llvm.aarch64.sve.sqdecd.n64(i64 [[OP:%.*]], i32 31, i32 1)
// CPP-CHECK-NEXT:    ret i64 [[TMP0]]
//
int64_t test_svqdecd_n_s64(int64_t op)
{
  return SVE_ACLE_FUNC(svqdecd,_n_s64,,)(op, 1);
}

// CHECK-LABEL: @test_svqdecd_n_u32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call i32 @llvm.aarch64.sve.uqdecd.n32(i32 [[OP:%.*]], i32 31, i32 16)
// CHECK-NEXT:    ret i32 [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z18test_svqdecd_n_u32j(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call i32 @llvm.aarch64.sve.uqdecd.n32(i32 [[OP:%.*]], i32 31, i32 16)
// CPP-CHECK-NEXT:    ret i32 [[TMP0]]
//
uint32_t test_svqdecd_n_u32(uint32_t op)
{
  return SVE_ACLE_FUNC(svqdecd,_n_u32,,)(op, 16);
}

// CHECK-LABEL: @test_svqdecd_n_u64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call i64 @llvm.aarch64.sve.uqdecd.n64(i64 [[OP:%.*]], i32 31, i32 1)
// CHECK-NEXT:    ret i64 [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z18test_svqdecd_n_u64m(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call i64 @llvm.aarch64.sve.uqdecd.n64(i64 [[OP:%.*]], i32 31, i32 1)
// CPP-CHECK-NEXT:    ret i64 [[TMP0]]
//
uint64_t test_svqdecd_n_u64(uint64_t op)
{
  return SVE_ACLE_FUNC(svqdecd,_n_u64,,)(op, 1);
}

// CHECK-LABEL: @test_svqdecd_pat_n_s32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call i32 @llvm.aarch64.sve.sqdecd.n32(i32 [[OP:%.*]], i32 4, i32 16)
// CHECK-NEXT:    ret i32 [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z22test_svqdecd_pat_n_s32i(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call i32 @llvm.aarch64.sve.sqdecd.n32(i32 [[OP:%.*]], i32 4, i32 16)
// CPP-CHECK-NEXT:    ret i32 [[TMP0]]
//
int32_t test_svqdecd_pat_n_s32(int32_t op)
{
  return SVE_ACLE_FUNC(svqdecd_pat,_n_s32,,)(op, SV_VL4, 16);
}

// CHECK-LABEL: @test_svqdecd_pat_n_s64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call i64 @llvm.aarch64.sve.sqdecd.n64(i64 [[OP:%.*]], i32 5, i32 1)
// CHECK-NEXT:    ret i64 [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z22test_svqdecd_pat_n_s64l(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call i64 @llvm.aarch64.sve.sqdecd.n64(i64 [[OP:%.*]], i32 5, i32 1)
// CPP-CHECK-NEXT:    ret i64 [[TMP0]]
//
int64_t test_svqdecd_pat_n_s64(int64_t op)
{
  return SVE_ACLE_FUNC(svqdecd_pat,_n_s64,,)(op, SV_VL5, 1);
}

// CHECK-LABEL: @test_svqdecd_pat_n_u32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call i32 @llvm.aarch64.sve.uqdecd.n32(i32 [[OP:%.*]], i32 6, i32 16)
// CHECK-NEXT:    ret i32 [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z22test_svqdecd_pat_n_u32j(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call i32 @llvm.aarch64.sve.uqdecd.n32(i32 [[OP:%.*]], i32 6, i32 16)
// CPP-CHECK-NEXT:    ret i32 [[TMP0]]
//
uint32_t test_svqdecd_pat_n_u32(uint32_t op)
{
  return SVE_ACLE_FUNC(svqdecd_pat,_n_u32,,)(op, SV_VL6, 16);
}

// CHECK-LABEL: @test_svqdecd_pat_n_u64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call i64 @llvm.aarch64.sve.uqdecd.n64(i64 [[OP:%.*]], i32 7, i32 1)
// CHECK-NEXT:    ret i64 [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z22test_svqdecd_pat_n_u64m(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call i64 @llvm.aarch64.sve.uqdecd.n64(i64 [[OP:%.*]], i32 7, i32 1)
// CPP-CHECK-NEXT:    ret i64 [[TMP0]]
//
uint64_t test_svqdecd_pat_n_u64(uint64_t op)
{
  return SVE_ACLE_FUNC(svqdecd_pat,_n_u64,,)(op, SV_VL7, 1);
}

// CHECK-LABEL: @test_svqdecd_s64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i64> @llvm.aarch64.sve.sqdecd.nxv2i64(<vscale x 2 x i64> [[OP:%.*]], i32 31, i32 16)
// CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z16test_svqdecd_s64u11__SVInt64_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i64> @llvm.aarch64.sve.sqdecd.nxv2i64(<vscale x 2 x i64> [[OP:%.*]], i32 31, i32 16)
// CPP-CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
svint64_t test_svqdecd_s64(svint64_t op)
{
  return SVE_ACLE_FUNC(svqdecd,_s64,,)(op, 16);
}

// CHECK-LABEL: @test_svqdecd_u64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i64> @llvm.aarch64.sve.uqdecd.nxv2i64(<vscale x 2 x i64> [[OP:%.*]], i32 31, i32 1)
// CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z16test_svqdecd_u64u12__SVUint64_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i64> @llvm.aarch64.sve.uqdecd.nxv2i64(<vscale x 2 x i64> [[OP:%.*]], i32 31, i32 1)
// CPP-CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
svuint64_t test_svqdecd_u64(svuint64_t op)
{
  return SVE_ACLE_FUNC(svqdecd,_u64,,)(op, 1);
}

// CHECK-LABEL: @test_svqdecd_pat_s64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i64> @llvm.aarch64.sve.sqdecd.nxv2i64(<vscale x 2 x i64> [[OP:%.*]], i32 8, i32 16)
// CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z20test_svqdecd_pat_s64u11__SVInt64_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i64> @llvm.aarch64.sve.sqdecd.nxv2i64(<vscale x 2 x i64> [[OP:%.*]], i32 8, i32 16)
// CPP-CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
svint64_t test_svqdecd_pat_s64(svint64_t op)
{
  return SVE_ACLE_FUNC(svqdecd_pat,_s64,,)(op, SV_VL8, 16);
}

// CHECK-LABEL: @test_svqdecd_pat_u64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i64> @llvm.aarch64.sve.uqdecd.nxv2i64(<vscale x 2 x i64> [[OP:%.*]], i32 9, i32 1)
// CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z20test_svqdecd_pat_u64u12__SVUint64_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i64> @llvm.aarch64.sve.uqdecd.nxv2i64(<vscale x 2 x i64> [[OP:%.*]], i32 9, i32 1)
// CPP-CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
svuint64_t test_svqdecd_pat_u64(svuint64_t op)
{
  return SVE_ACLE_FUNC(svqdecd_pat,_u64,,)(op, SV_VL16, 1);
}
