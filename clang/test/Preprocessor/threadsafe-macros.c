// RUN: %clang_cc1 -E -dM -fno-threadsafe-macros < /dev/null | FileCheck -match-full-lines %s
// RUN: %clang_cc1 -E -dM -fno-threadsafe-macros -triple powerpc64-ibm-aix  < /dev/null | FileCheck -match-full-lines %s
// RUN: %clang_cc1 -E -dM -fno-threadsafe-macros -triple powerpc64le-linux-gnu < /dev/null | FileCheck -match-full-lines %s
//
// CHECK-NOT: #define _REENTRANT 1
// CHECK-NOT: #define _THREAD_SAFE 1

// RUN: %clang_cc1 -E -dM -fthreadsafe-macros -triple powerpc64le-linux-gnu < /dev/null | FileCheck -match-full-lines -check-prefix THREADSAFE-GNU %s
// RUN: %clang_cc1 -E -dM -fthreadsafe-macros -triple powerpc64-ibm-aix < /dev/null | FileCheck -match-full-lines -check-prefix THREADSAFE-AIX %s
//
// THREADSAFE-GNU: #define _REENTRANT 1
// THREADSAFE-AIX: #define _THREAD_SAFE 1
