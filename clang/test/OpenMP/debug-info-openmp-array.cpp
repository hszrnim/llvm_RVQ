// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --function-signature --include-generated-funcs --replace-value-regex "__omp_offloading_[0-9a-z]+_[0-9a-z]+" "reduction_size[.].+[.]" "pl_cond[.].+[.|,]" --prefix-filecheck-ir-name _
// RUN: %clang_cc1 -triple x86_64-unknown-linux -fopenmp -x c++ %s -verify -debug-info-kind=limited -emit-llvm -o - | FileCheck %s --check-prefix=CHECK1

// RUN: %clang_cc1 -triple x86_64-unknown-linux -fopenmp-simd -x c++ %s -verify -debug-info-kind=limited -emit-llvm -o - | FileCheck %s --implicit-check-not="{{__kmpc|__tgt}}"
// expected-no-diagnostics

void f(int m) {
  int i;
  int cen[m];
#pragma omp parallel for
  for (i = 0; i < m; ++i) {
    cen[i] = i;
  }
}

// CHECK1-LABEL: define {{[^@]+}}@_Z1fi
// CHECK1-SAME: (i32 noundef [[M:%.*]]) #[[ATTR0:[0-9]+]] !dbg [[DBG6:![0-9]+]] {
// CHECK1-NEXT:  entry:
// CHECK1-NEXT:    [[M_ADDR:%.*]] = alloca i32, align 4
// CHECK1-NEXT:    [[I:%.*]] = alloca i32, align 4
// CHECK1-NEXT:    [[SAVED_STACK:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    [[__VLA_EXPR0:%.*]] = alloca i64, align 8
// CHECK1-NEXT:    store i32 [[M]], ptr [[M_ADDR]], align 4
// CHECK1-NEXT:    call void @llvm.dbg.declare(metadata ptr [[M_ADDR]], metadata [[META11:![0-9]+]], metadata !DIExpression()), !dbg [[DBG12:![0-9]+]]
// CHECK1-NEXT:    call void @llvm.dbg.declare(metadata ptr [[I]], metadata [[META13:![0-9]+]], metadata !DIExpression()), !dbg [[DBG14:![0-9]+]]
// CHECK1-NEXT:    [[TMP0:%.*]] = load i32, ptr [[M_ADDR]], align 4, !dbg [[DBG15:![0-9]+]]
// CHECK1-NEXT:    [[TMP1:%.*]] = zext i32 [[TMP0]] to i64, !dbg [[DBG16:![0-9]+]]
// CHECK1-NEXT:    [[TMP2:%.*]] = call ptr @llvm.stacksave(), !dbg [[DBG16]]
// CHECK1-NEXT:    store ptr [[TMP2]], ptr [[SAVED_STACK]], align 8, !dbg [[DBG16]]
// CHECK1-NEXT:    [[VLA:%.*]] = alloca i32, i64 [[TMP1]], align 16, !dbg [[DBG16]]
// CHECK1-NEXT:    store i64 [[TMP1]], ptr [[__VLA_EXPR0]], align 8, !dbg [[DBG16]]
// CHECK1-NEXT:    call void @llvm.dbg.declare(metadata ptr [[__VLA_EXPR0]], metadata [[META17:![0-9]+]], metadata !DIExpression()), !dbg [[DBG19:![0-9]+]]
// CHECK1-NEXT:    call void @llvm.dbg.declare(metadata ptr [[VLA]], metadata [[META20:![0-9]+]], metadata !DIExpression()), !dbg [[DBG24:![0-9]+]]
// CHECK1-NEXT:    call void (ptr, i32, ptr, ...) @__kmpc_fork_call(ptr @[[GLOB4:[0-9]+]], i32 3, ptr @.omp_outlined., ptr [[M_ADDR]], i64 [[TMP1]], ptr [[VLA]]), !dbg [[DBG25:![0-9]+]]
// CHECK1-NEXT:    [[TMP3:%.*]] = load ptr, ptr [[SAVED_STACK]], align 8, !dbg [[DBG26:![0-9]+]]
// CHECK1-NEXT:    call void @llvm.stackrestore(ptr [[TMP3]]), !dbg [[DBG26]]
// CHECK1-NEXT:    ret void, !dbg [[DBG26]]
//
//
// CHECK1-LABEL: define {{[^@]+}}@.omp_outlined._debug__
// CHECK1-SAME: (ptr noalias noundef [[DOTGLOBAL_TID_:%.*]], ptr noalias noundef [[DOTBOUND_TID_:%.*]], ptr noundef nonnull align 4 dereferenceable(4) [[M:%.*]], i64 noundef [[VLA:%.*]], ptr noundef nonnull align 4 dereferenceable(4) [[CEN:%.*]]) #[[ATTR3:[0-9]+]] !dbg [[DBG27:![0-9]+]] {
// CHECK1-NEXT:  entry:
// CHECK1-NEXT:    [[DOTGLOBAL_TID__ADDR:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    [[DOTBOUND_TID__ADDR:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    [[M_ADDR:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    [[VLA_ADDR:%.*]] = alloca i64, align 8
// CHECK1-NEXT:    [[CEN_ADDR:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    [[DOTOMP_IV:%.*]] = alloca i32, align 4
// CHECK1-NEXT:    [[TMP:%.*]] = alloca i32, align 4
// CHECK1-NEXT:    [[DOTCAPTURE_EXPR_:%.*]] = alloca i32, align 4
// CHECK1-NEXT:    [[DOTCAPTURE_EXPR_1:%.*]] = alloca i32, align 4
// CHECK1-NEXT:    [[I:%.*]] = alloca i32, align 4
// CHECK1-NEXT:    [[DOTOMP_LB:%.*]] = alloca i32, align 4
// CHECK1-NEXT:    [[DOTOMP_UB:%.*]] = alloca i32, align 4
// CHECK1-NEXT:    [[DOTOMP_STRIDE:%.*]] = alloca i32, align 4
// CHECK1-NEXT:    [[DOTOMP_IS_LAST:%.*]] = alloca i32, align 4
// CHECK1-NEXT:    [[I3:%.*]] = alloca i32, align 4
// CHECK1-NEXT:    store ptr [[DOTGLOBAL_TID_]], ptr [[DOTGLOBAL_TID__ADDR]], align 8
// CHECK1-NEXT:    call void @llvm.dbg.declare(metadata ptr [[DOTGLOBAL_TID__ADDR]], metadata [[META35:![0-9]+]], metadata !DIExpression()), !dbg [[DBG36:![0-9]+]]
// CHECK1-NEXT:    store ptr [[DOTBOUND_TID_]], ptr [[DOTBOUND_TID__ADDR]], align 8
// CHECK1-NEXT:    call void @llvm.dbg.declare(metadata ptr [[DOTBOUND_TID__ADDR]], metadata [[META37:![0-9]+]], metadata !DIExpression()), !dbg [[DBG36]]
// CHECK1-NEXT:    store ptr [[M]], ptr [[M_ADDR]], align 8
// CHECK1-NEXT:    call void @llvm.dbg.declare(metadata ptr [[M_ADDR]], metadata [[META38:![0-9]+]], metadata !DIExpression()), !dbg [[DBG39:![0-9]+]]
// CHECK1-NEXT:    store i64 [[VLA]], ptr [[VLA_ADDR]], align 8
// CHECK1-NEXT:    call void @llvm.dbg.declare(metadata ptr [[VLA_ADDR]], metadata [[META40:![0-9]+]], metadata !DIExpression()), !dbg [[DBG36]]
// CHECK1-NEXT:    store ptr [[CEN]], ptr [[CEN_ADDR]], align 8
// CHECK1-NEXT:    call void @llvm.dbg.declare(metadata ptr [[CEN_ADDR]], metadata [[META41:![0-9]+]], metadata !DIExpression()), !dbg [[DBG42:![0-9]+]]
// CHECK1-NEXT:    [[TMP0:%.*]] = load ptr, ptr [[M_ADDR]], align 8, !dbg [[DBG43:![0-9]+]]
// CHECK1-NEXT:    [[TMP1:%.*]] = load i64, ptr [[VLA_ADDR]], align 8, !dbg [[DBG43]]
// CHECK1-NEXT:    [[TMP2:%.*]] = load ptr, ptr [[CEN_ADDR]], align 8, !dbg [[DBG43]]
// CHECK1-NEXT:    call void @llvm.dbg.declare(metadata ptr [[DOTOMP_IV]], metadata [[META44:![0-9]+]], metadata !DIExpression()), !dbg [[DBG36]]
// CHECK1-NEXT:    call void @llvm.dbg.declare(metadata ptr [[DOTCAPTURE_EXPR_]], metadata [[META45:![0-9]+]], metadata !DIExpression()), !dbg [[DBG36]]
// CHECK1-NEXT:    [[TMP3:%.*]] = load i32, ptr [[TMP0]], align 4, !dbg [[DBG46:![0-9]+]]
// CHECK1-NEXT:    store i32 [[TMP3]], ptr [[DOTCAPTURE_EXPR_]], align 4, !dbg [[DBG46]]
// CHECK1-NEXT:    call void @llvm.dbg.declare(metadata ptr [[DOTCAPTURE_EXPR_1]], metadata [[META45]], metadata !DIExpression()), !dbg [[DBG36]]
// CHECK1-NEXT:    [[TMP4:%.*]] = load i32, ptr [[DOTCAPTURE_EXPR_]], align 4, !dbg [[DBG46]]
// CHECK1-NEXT:    [[SUB:%.*]] = sub nsw i32 [[TMP4]], 0, !dbg [[DBG43]]
// CHECK1-NEXT:    [[DIV:%.*]] = sdiv i32 [[SUB]], 1, !dbg [[DBG43]]
// CHECK1-NEXT:    [[SUB2:%.*]] = sub nsw i32 [[DIV]], 1, !dbg [[DBG43]]
// CHECK1-NEXT:    store i32 [[SUB2]], ptr [[DOTCAPTURE_EXPR_1]], align 4, !dbg [[DBG43]]
// CHECK1-NEXT:    call void @llvm.dbg.declare(metadata ptr [[I]], metadata [[META47:![0-9]+]], metadata !DIExpression()), !dbg [[DBG36]]
// CHECK1-NEXT:    store i32 0, ptr [[I]], align 4, !dbg [[DBG48:![0-9]+]]
// CHECK1-NEXT:    [[TMP5:%.*]] = load i32, ptr [[DOTCAPTURE_EXPR_]], align 4, !dbg [[DBG46]]
// CHECK1-NEXT:    [[CMP:%.*]] = icmp slt i32 0, [[TMP5]], !dbg [[DBG43]]
// CHECK1-NEXT:    br i1 [[CMP]], label [[OMP_PRECOND_THEN:%.*]], label [[OMP_PRECOND_END:%.*]], !dbg [[DBG43]]
// CHECK1:       omp.precond.then:
// CHECK1-NEXT:    call void @llvm.dbg.declare(metadata ptr [[DOTOMP_LB]], metadata [[META49:![0-9]+]], metadata !DIExpression()), !dbg [[DBG36]]
// CHECK1-NEXT:    store i32 0, ptr [[DOTOMP_LB]], align 4, !dbg [[DBG50:![0-9]+]]
// CHECK1-NEXT:    call void @llvm.dbg.declare(metadata ptr [[DOTOMP_UB]], metadata [[META51:![0-9]+]], metadata !DIExpression()), !dbg [[DBG36]]
// CHECK1-NEXT:    [[TMP6:%.*]] = load i32, ptr [[DOTCAPTURE_EXPR_1]], align 4, !dbg [[DBG43]]
// CHECK1-NEXT:    store i32 [[TMP6]], ptr [[DOTOMP_UB]], align 4, !dbg [[DBG50]]
// CHECK1-NEXT:    call void @llvm.dbg.declare(metadata ptr [[DOTOMP_STRIDE]], metadata [[META52:![0-9]+]], metadata !DIExpression()), !dbg [[DBG36]]
// CHECK1-NEXT:    store i32 1, ptr [[DOTOMP_STRIDE]], align 4, !dbg [[DBG50]]
// CHECK1-NEXT:    call void @llvm.dbg.declare(metadata ptr [[DOTOMP_IS_LAST]], metadata [[META53:![0-9]+]], metadata !DIExpression()), !dbg [[DBG36]]
// CHECK1-NEXT:    store i32 0, ptr [[DOTOMP_IS_LAST]], align 4, !dbg [[DBG50]]
// CHECK1-NEXT:    call void @llvm.dbg.declare(metadata ptr [[I3]], metadata [[META47]], metadata !DIExpression()), !dbg [[DBG36]]
// CHECK1-NEXT:    [[TMP7:%.*]] = load ptr, ptr [[DOTGLOBAL_TID__ADDR]], align 8, !dbg [[DBG43]]
// CHECK1-NEXT:    [[TMP8:%.*]] = load i32, ptr [[TMP7]], align 4, !dbg [[DBG43]]
// CHECK1-NEXT:    call void @__kmpc_for_static_init_4(ptr @[[GLOB1:[0-9]+]], i32 [[TMP8]], i32 34, ptr [[DOTOMP_IS_LAST]], ptr [[DOTOMP_LB]], ptr [[DOTOMP_UB]], ptr [[DOTOMP_STRIDE]], i32 1, i32 1), !dbg [[DBG54:![0-9]+]]
// CHECK1-NEXT:    [[TMP9:%.*]] = load i32, ptr [[DOTOMP_UB]], align 4, !dbg [[DBG50]]
// CHECK1-NEXT:    [[TMP10:%.*]] = load i32, ptr [[DOTCAPTURE_EXPR_1]], align 4, !dbg [[DBG43]]
// CHECK1-NEXT:    [[CMP4:%.*]] = icmp sgt i32 [[TMP9]], [[TMP10]], !dbg [[DBG50]]
// CHECK1-NEXT:    br i1 [[CMP4]], label [[COND_TRUE:%.*]], label [[COND_FALSE:%.*]], !dbg [[DBG50]]
// CHECK1:       cond.true:
// CHECK1-NEXT:    [[TMP11:%.*]] = load i32, ptr [[DOTCAPTURE_EXPR_1]], align 4, !dbg [[DBG43]]
// CHECK1-NEXT:    br label [[COND_END:%.*]], !dbg [[DBG50]]
// CHECK1:       cond.false:
// CHECK1-NEXT:    [[TMP12:%.*]] = load i32, ptr [[DOTOMP_UB]], align 4, !dbg [[DBG50]]
// CHECK1-NEXT:    br label [[COND_END]], !dbg [[DBG50]]
// CHECK1:       cond.end:
// CHECK1-NEXT:    [[COND:%.*]] = phi i32 [ [[TMP11]], [[COND_TRUE]] ], [ [[TMP12]], [[COND_FALSE]] ], !dbg [[DBG50]]
// CHECK1-NEXT:    store i32 [[COND]], ptr [[DOTOMP_UB]], align 4, !dbg [[DBG50]]
// CHECK1-NEXT:    [[TMP13:%.*]] = load i32, ptr [[DOTOMP_LB]], align 4, !dbg [[DBG50]]
// CHECK1-NEXT:    store i32 [[TMP13]], ptr [[DOTOMP_IV]], align 4, !dbg [[DBG50]]
// CHECK1-NEXT:    br label [[OMP_INNER_FOR_COND:%.*]], !dbg [[DBG43]]
// CHECK1:       omp.inner.for.cond:
// CHECK1-NEXT:    [[TMP14:%.*]] = load i32, ptr [[DOTOMP_IV]], align 4, !dbg [[DBG50]]
// CHECK1-NEXT:    [[TMP15:%.*]] = load i32, ptr [[DOTOMP_UB]], align 4, !dbg [[DBG50]]
// CHECK1-NEXT:    [[CMP5:%.*]] = icmp sle i32 [[TMP14]], [[TMP15]], !dbg [[DBG43]]
// CHECK1-NEXT:    br i1 [[CMP5]], label [[OMP_INNER_FOR_BODY:%.*]], label [[OMP_INNER_FOR_END:%.*]], !dbg [[DBG43]]
// CHECK1:       omp.inner.for.body:
// CHECK1-NEXT:    [[TMP16:%.*]] = load i32, ptr [[DOTOMP_IV]], align 4, !dbg [[DBG50]]
// CHECK1-NEXT:    [[MUL:%.*]] = mul nsw i32 [[TMP16]], 1, !dbg [[DBG48]]
// CHECK1-NEXT:    [[ADD:%.*]] = add nsw i32 0, [[MUL]], !dbg [[DBG48]]
// CHECK1-NEXT:    store i32 [[ADD]], ptr [[I3]], align 4, !dbg [[DBG48]]
// CHECK1-NEXT:    [[TMP17:%.*]] = load i32, ptr [[I3]], align 4, !dbg [[DBG55:![0-9]+]]
// CHECK1-NEXT:    [[TMP18:%.*]] = load i32, ptr [[I3]], align 4, !dbg [[DBG57:![0-9]+]]
// CHECK1-NEXT:    [[IDXPROM:%.*]] = sext i32 [[TMP18]] to i64, !dbg [[DBG58:![0-9]+]]
// CHECK1-NEXT:    [[ARRAYIDX:%.*]] = getelementptr inbounds i32, ptr [[TMP2]], i64 [[IDXPROM]], !dbg [[DBG58]]
// CHECK1-NEXT:    store i32 [[TMP17]], ptr [[ARRAYIDX]], align 4, !dbg [[DBG59:![0-9]+]]
// CHECK1-NEXT:    br label [[OMP_BODY_CONTINUE:%.*]], !dbg [[DBG60:![0-9]+]]
// CHECK1:       omp.body.continue:
// CHECK1-NEXT:    br label [[OMP_INNER_FOR_INC:%.*]], !dbg [[DBG54]]
// CHECK1:       omp.inner.for.inc:
// CHECK1-NEXT:    [[TMP19:%.*]] = load i32, ptr [[DOTOMP_IV]], align 4, !dbg [[DBG50]]
// CHECK1-NEXT:    [[ADD6:%.*]] = add nsw i32 [[TMP19]], 1, !dbg [[DBG43]]
// CHECK1-NEXT:    store i32 [[ADD6]], ptr [[DOTOMP_IV]], align 4, !dbg [[DBG43]]
// CHECK1-NEXT:    br label [[OMP_INNER_FOR_COND]], !dbg [[DBG54]], !llvm.loop [[LOOP61:![0-9]+]]
// CHECK1:       omp.inner.for.end:
// CHECK1-NEXT:    br label [[OMP_LOOP_EXIT:%.*]], !dbg [[DBG54]]
// CHECK1:       omp.loop.exit:
// CHECK1-NEXT:    [[TMP20:%.*]] = load ptr, ptr [[DOTGLOBAL_TID__ADDR]], align 8, !dbg [[DBG54]]
// CHECK1-NEXT:    [[TMP21:%.*]] = load i32, ptr [[TMP20]], align 4, !dbg [[DBG54]]
// CHECK1-NEXT:    call void @__kmpc_for_static_fini(ptr @[[GLOB3:[0-9]+]], i32 [[TMP21]]), !dbg [[DBG62:![0-9]+]]
// CHECK1-NEXT:    br label [[OMP_PRECOND_END]], !dbg [[DBG54]]
// CHECK1:       omp.precond.end:
// CHECK1-NEXT:    ret void, !dbg [[DBG63:![0-9]+]]
//
//
// CHECK1-LABEL: define {{[^@]+}}@.omp_outlined.
// CHECK1-SAME: (ptr noalias noundef [[DOTGLOBAL_TID_:%.*]], ptr noalias noundef [[DOTBOUND_TID_:%.*]], ptr noundef nonnull align 4 dereferenceable(4) [[M:%.*]], i64 noundef [[VLA:%.*]], ptr noundef nonnull align 4 dereferenceable(4) [[CEN:%.*]]) #[[ATTR3]] !dbg [[DBG64:![0-9]+]] {
// CHECK1-NEXT:  entry:
// CHECK1-NEXT:    [[DOTGLOBAL_TID__ADDR:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    [[DOTBOUND_TID__ADDR:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    [[M_ADDR:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    [[VLA_ADDR:%.*]] = alloca i64, align 8
// CHECK1-NEXT:    [[CEN_ADDR:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    store ptr [[DOTGLOBAL_TID_]], ptr [[DOTGLOBAL_TID__ADDR]], align 8
// CHECK1-NEXT:    call void @llvm.dbg.declare(metadata ptr [[DOTGLOBAL_TID__ADDR]], metadata [[META65:![0-9]+]], metadata !DIExpression()), !dbg [[DBG66:![0-9]+]]
// CHECK1-NEXT:    store ptr [[DOTBOUND_TID_]], ptr [[DOTBOUND_TID__ADDR]], align 8
// CHECK1-NEXT:    call void @llvm.dbg.declare(metadata ptr [[DOTBOUND_TID__ADDR]], metadata [[META67:![0-9]+]], metadata !DIExpression()), !dbg [[DBG66]]
// CHECK1-NEXT:    store ptr [[M]], ptr [[M_ADDR]], align 8
// CHECK1-NEXT:    call void @llvm.dbg.declare(metadata ptr [[M_ADDR]], metadata [[META68:![0-9]+]], metadata !DIExpression()), !dbg [[DBG66]]
// CHECK1-NEXT:    store i64 [[VLA]], ptr [[VLA_ADDR]], align 8
// CHECK1-NEXT:    call void @llvm.dbg.declare(metadata ptr [[VLA_ADDR]], metadata [[META69:![0-9]+]], metadata !DIExpression()), !dbg [[DBG66]]
// CHECK1-NEXT:    store ptr [[CEN]], ptr [[CEN_ADDR]], align 8
// CHECK1-NEXT:    call void @llvm.dbg.declare(metadata ptr [[CEN_ADDR]], metadata [[META70:![0-9]+]], metadata !DIExpression()), !dbg [[DBG66]]
// CHECK1-NEXT:    [[TMP0:%.*]] = load ptr, ptr [[M_ADDR]], align 8, !dbg [[DBG71:![0-9]+]]
// CHECK1-NEXT:    [[TMP1:%.*]] = load i64, ptr [[VLA_ADDR]], align 8, !dbg [[DBG71]]
// CHECK1-NEXT:    [[TMP2:%.*]] = load ptr, ptr [[CEN_ADDR]], align 8, !dbg [[DBG71]]
// CHECK1-NEXT:    [[TMP3:%.*]] = load ptr, ptr [[DOTGLOBAL_TID__ADDR]], align 8, !dbg [[DBG71]]
// CHECK1-NEXT:    [[TMP4:%.*]] = load ptr, ptr [[DOTBOUND_TID__ADDR]], align 8, !dbg [[DBG71]]
// CHECK1-NEXT:    [[TMP5:%.*]] = load ptr, ptr [[M_ADDR]], align 8, !dbg [[DBG71]]
// CHECK1-NEXT:    [[TMP6:%.*]] = load ptr, ptr [[CEN_ADDR]], align 8, !dbg [[DBG71]]
// CHECK1-NEXT:    call void @.omp_outlined._debug__(ptr [[TMP3]], ptr [[TMP4]], ptr [[TMP5]], i64 [[TMP1]], ptr [[TMP6]]) #[[ATTR4:[0-9]+]], !dbg [[DBG71]]
// CHECK1-NEXT:    ret void, !dbg [[DBG71]]
//
//