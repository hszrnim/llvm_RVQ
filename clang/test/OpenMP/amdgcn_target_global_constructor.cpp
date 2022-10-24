// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --function-signature --include-generated-funcs --replace-value-regex "__omp_offloading_[0-9a-z]+_[0-9a-z]+" "reduction_size[.].+[.]" "pl_cond[.].+[.|,]" --prefix-filecheck-ir-name _
// REQUIRES: amdgpu-registered-target

// RUN: %clang_cc1 -fopenmp -x c++ -std=c++11 -triple x86_64-unknown-unknown -fopenmp-targets=amdgcn-amd-amdhsa -emit-llvm-bc %s -o %t-ppc-host.bc
// RUN: %clang_cc1 -fopenmp -x c++ -std=c++11 -triple amdgcn-amd-amdhsa -fopenmp-targets=amdgcn-amd-amdhsa -emit-llvm %s -fopenmp-is-device -fopenmp-host-ir-file-path %t-ppc-host.bc -o - | FileCheck %s
// expected-no-diagnostics
#ifndef HEADER
#define HEADER

void foo(void);

struct S {
  int a;
  S() : a(1) {}
  ~S() { foo(); }
};

#pragma omp declare target
S A;
#pragma omp end declare target

#endif
// CHECK-LABEL: define {{[^@]+}}@{{__omp_offloading_.*_.*}}_A_l19_ctor
// CHECK-SAME: () #[[ATTR0:[0-9]+]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    call void @_ZN1SC1Ev(ptr noundef nonnull align 4 dereferenceable(4) addrspacecast (ptr addrspace(1) @A to ptr)) #[[ATTR3:[0-9]+]]
// CHECK-NEXT:    ret void
//
//
// CHECK-LABEL: define {{[^@]+}}@_ZN1SC1Ev
// CHECK-SAME: (ptr noundef nonnull align 4 dereferenceable(4) [[THIS:%.*]]) unnamed_addr #[[ATTR1:[0-9]+]] comdat align 2 {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[THIS_ADDR:%.*]] = alloca ptr, align 8, addrspace(5)
// CHECK-NEXT:    [[THIS_ADDR_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[THIS_ADDR]] to ptr
// CHECK-NEXT:    store ptr [[THIS]], ptr [[THIS_ADDR_ASCAST]], align 8
// CHECK-NEXT:    [[THIS1:%.*]] = load ptr, ptr [[THIS_ADDR_ASCAST]], align 8
// CHECK-NEXT:    call void @_ZN1SC2Ev(ptr noundef nonnull align 4 dereferenceable(4) [[THIS1]]) #[[ATTR3]]
// CHECK-NEXT:    ret void
//
//
// CHECK-LABEL: define {{[^@]+}}@{{__omp_offloading_.*_.*}}_A_l19_dtor
// CHECK-SAME: () #[[ATTR0]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    call void @_ZN1SD1Ev(ptr noundef nonnull align 4 dereferenceable(4) addrspacecast (ptr addrspace(1) @A to ptr)) #[[ATTR4:[0-9]+]]
// CHECK-NEXT:    ret void
//
//
// CHECK-LABEL: define {{[^@]+}}@_ZN1SD1Ev
// CHECK-SAME: (ptr noundef nonnull align 4 dereferenceable(4) [[THIS:%.*]]) unnamed_addr #[[ATTR1]] comdat align 2 {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[THIS_ADDR:%.*]] = alloca ptr, align 8, addrspace(5)
// CHECK-NEXT:    [[THIS_ADDR_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[THIS_ADDR]] to ptr
// CHECK-NEXT:    store ptr [[THIS]], ptr [[THIS_ADDR_ASCAST]], align 8
// CHECK-NEXT:    [[THIS1:%.*]] = load ptr, ptr [[THIS_ADDR_ASCAST]], align 8
// CHECK-NEXT:    call void @_ZN1SD2Ev(ptr noundef nonnull align 4 dereferenceable(4) [[THIS1]]) #[[ATTR4]]
// CHECK-NEXT:    ret void
//
//
// CHECK-LABEL: define {{[^@]+}}@_ZN1SC2Ev
// CHECK-SAME: (ptr noundef nonnull align 4 dereferenceable(4) [[THIS:%.*]]) unnamed_addr #[[ATTR1]] comdat align 2 {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[THIS_ADDR:%.*]] = alloca ptr, align 8, addrspace(5)
// CHECK-NEXT:    [[THIS_ADDR_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[THIS_ADDR]] to ptr
// CHECK-NEXT:    store ptr [[THIS]], ptr [[THIS_ADDR_ASCAST]], align 8
// CHECK-NEXT:    [[THIS1:%.*]] = load ptr, ptr [[THIS_ADDR_ASCAST]], align 8
// CHECK-NEXT:    [[A:%.*]] = getelementptr inbounds [[STRUCT_S:%.*]], ptr [[THIS1]], i32 0, i32 0
// CHECK-NEXT:    store i32 1, ptr [[A]], align 4
// CHECK-NEXT:    ret void
//
//
// CHECK-LABEL: define {{[^@]+}}@_ZN1SD2Ev
// CHECK-SAME: (ptr noundef nonnull align 4 dereferenceable(4) [[THIS:%.*]]) unnamed_addr #[[ATTR1]] comdat align 2 {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[THIS_ADDR:%.*]] = alloca ptr, align 8, addrspace(5)
// CHECK-NEXT:    [[THIS_ADDR_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[THIS_ADDR]] to ptr
// CHECK-NEXT:    store ptr [[THIS]], ptr [[THIS_ADDR_ASCAST]], align 8
// CHECK-NEXT:    [[THIS1:%.*]] = load ptr, ptr [[THIS_ADDR_ASCAST]], align 8
// CHECK-NEXT:    call void @_Z3foov() #[[ATTR3]]
// CHECK-NEXT:    ret void
//