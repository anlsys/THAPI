#define __CUDA_API_VERSION_INTERNAL=1
#include <cuda.h>
  typedef
struct cuexp_function_arg_desc_query_st {
  size_t sz;
  size_t argSize;
  size_t argOffset;
  size_t u1;
  size_t u2;
}

  cuexp_function_arg_desc_query;
CUresult cuexp_function_get_name(CUcontext hContext, CUfunction hFunction, char **pName);
CUresult cuexpFunction_setCacheConfig(CUfunction hFunction,CUfunc_cache config);
CUresult cuexp_6e163fbe_d8(CUmodule hModule, int *pB);
CUresult cuexpFunction_get_arg_count(CUfunction hFunction, size_t *pArgCount);
CUresult cuexpFunction_get_arg_descriptor(CUfunction hFunction, size_t argIndex, cuexp_function_arg_desc_query *pArgDescQuery);
CUresult cuexp_6e163fbe_130(void **pA, CUfunction hFunction);
CUresult cuexp_module_iterate_on_functions(CUcontext hContext, CUmodule hModule, void *pFunc, void *userData);
CUresult cuexp_6e163fbe_1a8(CUfunction hFunction, int *pB);
CUresult cuexp_6e163fbe_1b8(CUfunction hFunction, unsigned long *pB);
unsigned int cuexpDevice_get_primary_context_refcount(CUdevice device);
CUresult cuexp_get_thread_context(CUcontext *phContext);
CUresult cuexp_a094798c_08(unsigned int a, void **b);
void cuexp_a094798c_10(void **a, size_t *b);
CUresult cuexp_a094798c_18(CUcontext hContext, void *a, void **b);
CUresult cuexp_a094798c_20(CUcontext hContext, uint64_t *b);
CUresult cuexp_a094798c_28(unsigned int a, void *b);
void cuexp_a094798c_30(void **a, size_t *b);
CUresult cuexpContext_kvstore_add(CUcontext hContext, void *handle, void* value, void *unknown);
CUresult cuexpContext_kvstore_delete(CUcontext hContext, void *handle);
CUresult cuexpContext_kvstore_get(void **value, CUcontext hContext, void *handle);
CUresult cuexp_get_primary_context(CUcontext *phContext, unsigned int ordinal);
CUresult cuexp_register_module(CUmodule* phModule, int* fatBinary, void *a, void *b, unsigned int ordinal);
void cuexp_unregister_module(int *fatBinary);
CUresult cuexpContext_getDevice(CUcontext hContext, CUdevice *pDevice);
CUresult cuexpContext_getContextNumber(CUcontext hContext, unsigned long *contextNumber);
CUresult cuexp_21318c60_80(void *a,void **pB);
CUresult cuexp_21318c60_138(CUcontext hContext, void *b, void **pC);
CUresult cuexpDevice_get(CUdevice *pDevice, int ordinal);
CUresult cuexpDevice_getCount(unsigned int *pCount);
CUresult cuexpDevice_getAttribute(int ordinal,CUdevice_attribute attrib,int flag,long *pl);
CUresult cuexp_b10541e1_30(CUdevice device, void **pB);
CUresult cuexp_b10541e1_40(unsigned int *pRes, CUdevice device);
CUresult cuexp_a6b1ff99_28(void **a, CUcontext hContext);
CUresult cuexp_127d4831_28(void *h, int a, void **pB, void *param_4);
CUresult cuexp_127d4831_30(void *h, int a, void **pB);
  typedef
struct cuexp_7cb63f9b_1e0_struct_st {
  int unknown;
  unsigned int stride;
  unsigned int countOut;
  unsigned int capacity;
  void *data;
}

  cuexp_7cb63f9b_1e0_struct;
CUresult cuexpCUPTI_init(void);
CUresult cuexp_7cb63f9b_1e0(CUdevice device, cuexp_7cb63f9b_1e0_struct *b);
CUresult cuexp_2c8e0ad8_18(int *pRes,void *a,void *b);
CUresult cuexp_2c8e0ad8_38(int a, int b, unsigned int c);
CUresult cuexp_getCudaState(int *pState);
