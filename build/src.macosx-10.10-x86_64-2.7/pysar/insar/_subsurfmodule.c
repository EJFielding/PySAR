/* File: _subsurfmodule.c
 * This file is auto-generated with f2py (version:2).
 * f2py is a Fortran to Python Interface Generator (FPIG), Second Edition,
 * written by Pearu Peterson <pearu@cens.ioc.ee>.
 * See http://cens.ioc.ee/projects/f2py2e/
 * Generation date: Fri Aug 14 21:16:23 2015
 * $Revision:$
 * $Date:$
 * Do not edit this file directly unless you know what you are doing!!!
 */
#ifdef __cplusplus
extern "C" {
#endif

/*********************** See f2py2e/cfuncs.py: includes ***********************/
#include "Python.h"
#include <stdarg.h>
#include "fortranobject.h"
#include <math.h>

/**************** See f2py2e/rules.py: mod_rules['modulebody'] ****************/
static PyObject *_subsurf_error;
static PyObject *_subsurf_module;

/*********************** See f2py2e/cfuncs.py: typedefs ***********************/
#ifdef _WIN32
typedef __int64 long_long;
#else
typedef long long long_long;
typedef unsigned long long unsigned_long_long;
#endif


/****************** See f2py2e/cfuncs.py: typedefs_generated ******************/
/*need_typedefs_generated*/

/********************** See f2py2e/cfuncs.py: cppmacros **********************/
#if defined(PREPEND_FORTRAN)
#if defined(NO_APPEND_FORTRAN)
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) _##F
#else
#define F_FUNC(f,F) _##f
#endif
#else
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) _##F##_
#else
#define F_FUNC(f,F) _##f##_
#endif
#endif
#else
#if defined(NO_APPEND_FORTRAN)
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) F
#else
#define F_FUNC(f,F) f
#endif
#else
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) F##_
#else
#define F_FUNC(f,F) f##_
#endif
#endif
#endif
#if defined(UNDERSCORE_G77)
#define F_FUNC_US(f,F) F_FUNC(f##_,F##_)
#else
#define F_FUNC_US(f,F) F_FUNC(f,F)
#endif

#define rank(var) var ## _Rank
#define shape(var,dim) var ## _Dims[dim]
#define old_rank(var) (((PyArrayObject *)(capi_ ## var ## _tmp))->nd)
#define old_shape(var,dim) (((PyArrayObject *)(capi_ ## var ## _tmp))->dimensions[dim])
#define fshape(var,dim) shape(var,rank(var)-dim-1)
#define len(var) shape(var,0)
#define flen(var) fshape(var,0)
#define old_size(var) PyArray_SIZE((PyArrayObject *)(capi_ ## var ## _tmp))
/* #define index(i) capi_i ## i */
#define slen(var) capi_ ## var ## _len
#define size(var, ...) f2py_size((PyArrayObject *)(capi_ ## var ## _tmp), ## __VA_ARGS__, -1)

#define CHECKSCALAR(check,tcheck,name,show,var)\
  if (!(check)) {\
    char errstring[256];\
    sprintf(errstring, "%s: "show, "("tcheck") failed for "name, var);\
    PyErr_SetString(_subsurf_error,errstring);\
    /*goto capi_fail;*/\
  } else 
#ifdef DEBUGCFUNCS
#define CFUNCSMESS(mess) fprintf(stderr,"debug-capi:"mess);
#define CFUNCSMESSPY(mess,obj) CFUNCSMESS(mess) \
  PyObject_Print((PyObject *)obj,stderr,Py_PRINT_RAW);\
  fprintf(stderr,"\n");
#else
#define CFUNCSMESS(mess)
#define CFUNCSMESSPY(mess,obj)
#endif

#ifndef max
#define max(a,b) ((a > b) ? (a) : (b))
#endif
#ifndef min
#define min(a,b) ((a < b) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a,b) ((a > b) ? (a) : (b))
#endif
#ifndef MIN
#define MIN(a,b) ((a < b) ? (a) : (b))
#endif


/************************ See f2py2e/cfuncs.py: cfuncs ************************/
static int f2py_size(PyArrayObject* var, ...)
{
  npy_int sz = 0;
  npy_int dim;
  npy_int rank;
  va_list argp;
  va_start(argp, var);
  dim = va_arg(argp, npy_int);
  if (dim==-1)
    {
      sz = PyArray_SIZE(var);
    }
  else
    {
      rank = PyArray_NDIM(var);
      if (dim>=1 && dim<=rank)
        sz = PyArray_DIM(var, dim-1);
      else
        fprintf(stderr, "f2py_size: 2nd argument value=%d fails to satisfy 1<=value<=%d. Result will be 0.\n", dim, rank);
    }
  va_end(argp);
  return sz;
}

static int double_from_pyobj(double* v,PyObject *obj,const char *errmess) {
  PyObject* tmp = NULL;
  if (PyFloat_Check(obj)) {
#ifdef __sgi
    *v = PyFloat_AsDouble(obj);
#else
    *v = PyFloat_AS_DOUBLE(obj);
#endif
    return 1;
  }
  tmp = PyNumber_Float(obj);
  if (tmp) {
#ifdef __sgi
    *v = PyFloat_AsDouble(tmp);
#else
    *v = PyFloat_AS_DOUBLE(tmp);
#endif
    Py_DECREF(tmp);
    return 1;
  }
  if (PyComplex_Check(obj))
    tmp = PyObject_GetAttrString(obj,"real");
  else if (PyString_Check(obj) || PyUnicode_Check(obj))
    /*pass*/;
  else if (PySequence_Check(obj))
    tmp = PySequence_GetItem(obj,0);
  if (tmp) {
    PyErr_Clear();
    if (double_from_pyobj(v,tmp,errmess)) {Py_DECREF(tmp); return 1;}
    Py_DECREF(tmp);
  }
  {
    PyObject* err = PyErr_Occurred();
    if (err==NULL) err = _subsurf_error;
    PyErr_SetString(err,errmess);
  }
  return 0;
}

static int long_long_from_pyobj(long_long* v,PyObject *obj,const char *errmess) {
  PyObject* tmp = NULL;
  if (PyLong_Check(obj)) {
    *v = PyLong_AsLongLong(obj);
    return (!PyErr_Occurred());
  }
  if (PyInt_Check(obj)) {
    *v = (long_long)PyInt_AS_LONG(obj);
    return 1;
  }
  tmp = PyNumber_Long(obj);
  if (tmp) {
    *v = PyLong_AsLongLong(tmp);
    Py_DECREF(tmp);
    return (!PyErr_Occurred());
  }
  if (PyComplex_Check(obj))
    tmp = PyObject_GetAttrString(obj,"real");
  else if (PyString_Check(obj) || PyUnicode_Check(obj))
    /*pass*/;
  else if (PySequence_Check(obj))
    tmp = PySequence_GetItem(obj,0);
  if (tmp) {
    PyErr_Clear();
    if (long_long_from_pyobj(v,tmp,errmess)) {Py_DECREF(tmp); return 1;}
    Py_DECREF(tmp);
  }
  {
    PyObject* err = PyErr_Occurred();
    if (err==NULL) err = _subsurf_error;
    PyErr_SetString(err,errmess);
  }
  return 0;
}


/********************* See f2py2e/cfuncs.py: userincludes *********************/
/*need_userincludes*/

/********************* See f2py2e/capi_rules.py: usercode *********************/


/* See f2py2e/rules.py */
extern void F_FUNC(subsurf,SUBSURF)(double*,float*,float*,double*,long_long*,long_long*,long_long*,double*);
/*eof externroutines*/

/******************** See f2py2e/capi_rules.py: usercode1 ********************/


/******************* See f2py2e/cb_rules.py: buildcallback *******************/
/*need_callbacks*/

/*********************** See f2py2e/rules.py: buildapi ***********************/

/********************************** subsurf **********************************/
static char doc_f2py_rout__subsurf_subsurf[] = "\
subsurf(d,x,y,c,deg,nul,[lc,n])\n\nWrapper for ``subsurf``.\
\n\nParameters\n----------\n"
"d : in/output rank-1 array('d') with bounds (n)\n"
"x : input rank-1 array('f') with bounds (n)\n"
"y : input rank-1 array('f') with bounds (n)\n"
"c : input rank-1 array('d') with bounds (lc)\n"
"deg : input long\n"
"nul : input float\n"
"\nOther Parameters\n----------------\n"
"lc : input long, optional\n    Default: len(c)\n"
"n : input long, optional\n    Default: len(d)";
/* extern void F_FUNC(subsurf,SUBSURF)(double*,float*,float*,double*,long_long*,long_long*,long_long*,double*); */
static PyObject *f2py_rout__subsurf_subsurf(const PyObject *capi_self,
                           PyObject *capi_args,
                           PyObject *capi_keywds,
                           void (*f2py_func)(double*,float*,float*,double*,long_long*,long_long*,long_long*,double*)) {
  PyObject * volatile capi_buildvalue = NULL;
  volatile int f2py_success = 1;
/*decl*/

  double *d = NULL;
  npy_intp d_Dims[1] = {-1};
  const int d_Rank = 1;
  PyArrayObject *capi_d_tmp = NULL;
  int capi_d_intent = 0;
  PyObject *d_capi = Py_None;
  float *x = NULL;
  npy_intp x_Dims[1] = {-1};
  const int x_Rank = 1;
  PyArrayObject *capi_x_tmp = NULL;
  int capi_x_intent = 0;
  PyObject *x_capi = Py_None;
  float *y = NULL;
  npy_intp y_Dims[1] = {-1};
  const int y_Rank = 1;
  PyArrayObject *capi_y_tmp = NULL;
  int capi_y_intent = 0;
  PyObject *y_capi = Py_None;
  double *c = NULL;
  npy_intp c_Dims[1] = {-1};
  const int c_Rank = 1;
  PyArrayObject *capi_c_tmp = NULL;
  int capi_c_intent = 0;
  PyObject *c_capi = Py_None;
  long_long lc = 0;
  PyObject *lc_capi = Py_None;
  long_long n = 0;
  PyObject *n_capi = Py_None;
  long_long deg = 0;
  PyObject *deg_capi = Py_None;
  double nul = 0;
  PyObject *nul_capi = Py_None;
  static char *capi_kwlist[] = {"d","x","y","c","deg","nul","lc","n",NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_clock();
#endif
  if (!PyArg_ParseTupleAndKeywords(capi_args,capi_keywds,\
    "OOOOOO|OO:_subsurf.subsurf",\
    capi_kwlist,&d_capi,&x_capi,&y_capi,&c_capi,&deg_capi,&nul_capi,&lc_capi,&n_capi))
    return NULL;
/*frompyobj*/
  /* Processing variable c */
  ;
  capi_c_intent |= F2PY_INTENT_IN;
  capi_c_tmp = array_from_pyobj(NPY_DOUBLE,c_Dims,c_Rank,capi_c_intent,c_capi);
  if (capi_c_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(_subsurf_error,"failed in converting 4th argument `c' of _subsurf.subsurf to C/Fortran array" );
  } else {
    c = (double *)(capi_c_tmp->data);

  /* Processing variable nul */
    f2py_success = double_from_pyobj(&nul,nul_capi,"_subsurf.subsurf() 6th argument (nul) can't be converted to double");
  if (f2py_success) {
  /* Processing variable deg */
    f2py_success = long_long_from_pyobj(&deg,deg_capi,"_subsurf.subsurf() 5th argument (deg) can't be converted to long_long");
  if (f2py_success) {
  /* Processing variable d */
  ;
  capi_d_intent |= F2PY_INTENT_INOUT;
  capi_d_tmp = array_from_pyobj(NPY_DOUBLE,d_Dims,d_Rank,capi_d_intent,d_capi);
  if (capi_d_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(_subsurf_error,"failed in converting 1st argument `d' of _subsurf.subsurf to C/Fortran array" );
  } else {
    d = (double *)(capi_d_tmp->data);

  /* Processing variable lc */
  if (lc_capi == Py_None) lc = len(c); else
    f2py_success = long_long_from_pyobj(&lc,lc_capi,"_subsurf.subsurf() 1st keyword (lc) can't be converted to long_long");
  if (f2py_success) {
  CHECKSCALAR(len(c)>=lc,"len(c)>=lc","1st keyword lc","subsurf:lc=%ld",lc) {
  /* Processing variable n */
  if (n_capi == Py_None) n = len(d); else
    f2py_success = long_long_from_pyobj(&n,n_capi,"_subsurf.subsurf() 2nd keyword (n) can't be converted to long_long");
  if (f2py_success) {
  CHECKSCALAR(len(d)>=n,"len(d)>=n","2nd keyword n","subsurf:n=%ld",n) {
  /* Processing variable y */
  y_Dims[0]=n;
  capi_y_intent |= F2PY_INTENT_IN;
  capi_y_tmp = array_from_pyobj(NPY_FLOAT,y_Dims,y_Rank,capi_y_intent,y_capi);
  if (capi_y_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(_subsurf_error,"failed in converting 3rd argument `y' of _subsurf.subsurf to C/Fortran array" );
  } else {
    y = (float *)(capi_y_tmp->data);

  /* Processing variable x */
  x_Dims[0]=n;
  capi_x_intent |= F2PY_INTENT_IN;
  capi_x_tmp = array_from_pyobj(NPY_FLOAT,x_Dims,x_Rank,capi_x_intent,x_capi);
  if (capi_x_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(_subsurf_error,"failed in converting 2nd argument `x' of _subsurf.subsurf to C/Fortran array" );
  } else {
    x = (float *)(capi_x_tmp->data);

/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_call_clock();
#endif
/*callfortranroutine*/
        (*f2py_func)(d,x,y,c,&lc,&n,&deg,&nul);
if (PyErr_Occurred())
  f2py_success = 0;
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_call_clock();
#endif
/*end of callfortranroutine*/
    if (f2py_success) {
/*pyobjfrom*/
/*end of pyobjfrom*/
    CFUNCSMESS("Building return value.\n");
    capi_buildvalue = Py_BuildValue("");
/*closepyobjfrom*/
/*end of closepyobjfrom*/
    } /*if (f2py_success) after callfortranroutine*/
/*cleanupfrompyobj*/
  if((PyObject *)capi_x_tmp!=x_capi) {
    Py_XDECREF(capi_x_tmp); }
  }  /*if (capi_x_tmp == NULL) ... else of x*/
  /* End of cleaning variable x */
  if((PyObject *)capi_y_tmp!=y_capi) {
    Py_XDECREF(capi_y_tmp); }
  }  /*if (capi_y_tmp == NULL) ... else of y*/
  /* End of cleaning variable y */
  } /*CHECKSCALAR(len(d)>=n)*/
  } /*if (f2py_success) of n*/
  /* End of cleaning variable n */
  } /*CHECKSCALAR(len(c)>=lc)*/
  } /*if (f2py_success) of lc*/
  /* End of cleaning variable lc */
  if((PyObject *)capi_d_tmp!=d_capi) {
    Py_XDECREF(capi_d_tmp); }
  }  /*if (capi_d_tmp == NULL) ... else of d*/
  /* End of cleaning variable d */
  } /*if (f2py_success) of deg*/
  /* End of cleaning variable deg */
  } /*if (f2py_success) of nul*/
  /* End of cleaning variable nul */
  if((PyObject *)capi_c_tmp!=c_capi) {
    Py_XDECREF(capi_c_tmp); }
  }  /*if (capi_c_tmp == NULL) ... else of c*/
  /* End of cleaning variable c */
/*end of cleanupfrompyobj*/
  if (capi_buildvalue == NULL) {
/*routdebugfailure*/
  } else {
/*routdebugleave*/
  }
  CFUNCSMESS("Freeing memory.\n");
/*freemem*/
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_clock();
#endif
  return capi_buildvalue;
}
/******************************* end of subsurf *******************************/
/*eof body*/

/******************* See f2py2e/f90mod_rules.py: buildhooks *******************/
/*need_f90modhooks*/

/************** See f2py2e/rules.py: module_rules['modulebody'] **************/

/******************* See f2py2e/common_rules.py: buildhooks *******************/

/*need_commonhooks*/

/**************************** See f2py2e/rules.py ****************************/

static FortranDataDef f2py_routine_defs[] = {
  {"subsurf",-1,{{-1}},0,(char *)F_FUNC(subsurf,SUBSURF),(f2py_init_func)f2py_rout__subsurf_subsurf,doc_f2py_rout__subsurf_subsurf},

/*eof routine_defs*/
  {NULL}
};

static PyMethodDef f2py_module_methods[] = {

  {NULL,NULL}
};

#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef moduledef = {
  PyModuleDef_HEAD_INIT,
  "_subsurf",
  NULL,
  -1,
  f2py_module_methods,
  NULL,
  NULL,
  NULL,
  NULL
};
#endif

#if PY_VERSION_HEX >= 0x03000000
#define RETVAL m
PyMODINIT_FUNC PyInit__subsurf(void) {
#else
#define RETVAL
PyMODINIT_FUNC init_subsurf(void) {
#endif
  int i;
  PyObject *m,*d, *s;
#if PY_VERSION_HEX >= 0x03000000
  m = _subsurf_module = PyModule_Create(&moduledef);
#else
  m = _subsurf_module = Py_InitModule("_subsurf", f2py_module_methods);
#endif
  Py_TYPE(&PyFortran_Type) = &PyType_Type;
  import_array();
  if (PyErr_Occurred())
    {PyErr_SetString(PyExc_ImportError, "can't initialize module _subsurf (failed to import numpy)"); return RETVAL;}
  d = PyModule_GetDict(m);
  s = PyString_FromString("$Revision: $");
  PyDict_SetItemString(d, "__version__", s);
#if PY_VERSION_HEX >= 0x03000000
  s = PyUnicode_FromString(
#else
  s = PyString_FromString(
#endif
    "This module '_subsurf' is auto-generated with f2py (version:2).\nFunctions:\n"
"  subsurf(d,x,y,c,deg,nul,lc=len(c),n=len(d))\n"
".");
  PyDict_SetItemString(d, "__doc__", s);
  _subsurf_error = PyErr_NewException ("_subsurf.error", NULL, NULL);
  Py_DECREF(s);
  for(i=0;f2py_routine_defs[i].name!=NULL;i++)
    PyDict_SetItemString(d, f2py_routine_defs[i].name,PyFortranObject_NewAsAttr(&f2py_routine_defs[i]));

/*eof initf2pywraphooks*/
/*eof initf90modhooks*/

/*eof initcommonhooks*/


#ifdef F2PY_REPORT_ATEXIT
  if (! PyErr_Occurred())
    on_exit(f2py_report_on_exit,(void*)"_subsurf");
#endif

  return RETVAL;
}
#ifdef __cplusplus
}
#endif
