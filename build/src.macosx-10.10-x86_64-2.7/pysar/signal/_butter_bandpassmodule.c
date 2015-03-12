/* File: _butter_bandpassmodule.c
 * This file is auto-generated with f2py (version:2).
 * f2py is a Fortran to Python Interface Generator (FPIG), Second Edition,
 * written by Pearu Peterson <pearu@cens.ioc.ee>.
 * See http://cens.ioc.ee/projects/f2py2e/
 * Generation date: Wed Mar 11 21:59:56 2015
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
static PyObject *_butter_bandpass_error;
static PyObject *_butter_bandpass_module;

/*********************** See f2py2e/cfuncs.py: typedefs ***********************/
/*need_typedefs*/

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
    PyErr_SetString(_butter_bandpass_error,errstring);\
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
    if (err==NULL) err = _butter_bandpass_error;
    PyErr_SetString(err,errmess);
  }
  return 0;
}

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

static int float_from_pyobj(float* v,PyObject *obj,const char *errmess) {
  double d=0.0;
  if (double_from_pyobj(&d,obj,errmess)) {
    *v = (float)d;
    return 1;
  }
  return 0;
}

static int int_from_pyobj(int* v,PyObject *obj,const char *errmess) {
  PyObject* tmp = NULL;
  if (PyInt_Check(obj)) {
    *v = (int)PyInt_AS_LONG(obj);
    return 1;
  }
  tmp = PyNumber_Int(obj);
  if (tmp) {
    *v = PyInt_AS_LONG(tmp);
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
    if (int_from_pyobj(v,tmp,errmess)) {Py_DECREF(tmp); return 1;}
    Py_DECREF(tmp);
  }
  {
    PyObject* err = PyErr_Occurred();
    if (err==NULL) err = _butter_bandpass_error;
    PyErr_SetString(err,errmess);
  }
  return 0;
}


/********************* See f2py2e/cfuncs.py: userincludes *********************/
/*need_userincludes*/

/********************* See f2py2e/capi_rules.py: usercode *********************/


/* See f2py2e/rules.py */
extern void F_FUNC(bfilter,BFILTER)(float*,float*,float*,float*,float*,float*,float*,int*,int*,int*);
/*eof externroutines*/

/******************** See f2py2e/capi_rules.py: usercode1 ********************/


/******************* See f2py2e/cb_rules.py: buildcallback *******************/
/*need_callbacks*/

/*********************** See f2py2e/rules.py: buildapi ***********************/

/********************************** bfilter **********************************/
static char doc_f2py_rout__butter_bandpass_bfilter[] = "\
yr,er,ermx = bfilter(xr,f0,fc,dt,m,mzer,[n])\n\nWrapper for ``bfilter``.\
\n\nParameters\n----------\n"
"xr : input rank-1 array('f') with bounds (n)\n"
"f0 : input float\n"
"fc : input float\n"
"dt : input float\n"
"m : input int\n"
"mzer : input int\n"
"\nOther Parameters\n----------------\n"
"n : input int, optional\n    Default: len(xr)\n"
"\nReturns\n-------\n"
"yr : rank-1 array('f') with bounds (n)\n"
"er : rank-1 array('f') with bounds (n)\n"
"ermx : float";
/* extern void F_FUNC(bfilter,BFILTER)(float*,float*,float*,float*,float*,float*,float*,int*,int*,int*); */
static PyObject *f2py_rout__butter_bandpass_bfilter(const PyObject *capi_self,
                           PyObject *capi_args,
                           PyObject *capi_keywds,
                           void (*f2py_func)(float*,float*,float*,float*,float*,float*,float*,int*,int*,int*)) {
  PyObject * volatile capi_buildvalue = NULL;
  volatile int f2py_success = 1;
/*decl*/

  float *xr = NULL;
  npy_intp xr_Dims[1] = {-1};
  const int xr_Rank = 1;
  PyArrayObject *capi_xr_tmp = NULL;
  int capi_xr_intent = 0;
  PyObject *xr_capi = Py_None;
  float *yr = NULL;
  npy_intp yr_Dims[1] = {-1};
  const int yr_Rank = 1;
  PyArrayObject *capi_yr_tmp = NULL;
  int capi_yr_intent = 0;
  float *er = NULL;
  npy_intp er_Dims[1] = {-1};
  const int er_Rank = 1;
  PyArrayObject *capi_er_tmp = NULL;
  int capi_er_intent = 0;
  float ermx = 0;
  float f0 = 0;
  PyObject *f0_capi = Py_None;
  float fc = 0;
  PyObject *fc_capi = Py_None;
  float dt = 0;
  PyObject *dt_capi = Py_None;
  int m = 0;
  PyObject *m_capi = Py_None;
  int n = 0;
  PyObject *n_capi = Py_None;
  int mzer = 0;
  PyObject *mzer_capi = Py_None;
  static char *capi_kwlist[] = {"xr","f0","fc","dt","m","mzer","n",NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_clock();
#endif
  if (!PyArg_ParseTupleAndKeywords(capi_args,capi_keywds,\
    "OOOOOO|O:_butter_bandpass.bfilter",\
    capi_kwlist,&xr_capi,&f0_capi,&fc_capi,&dt_capi,&m_capi,&mzer_capi,&n_capi))
    return NULL;
/*frompyobj*/
  /* Processing variable f0 */
    f2py_success = float_from_pyobj(&f0,f0_capi,"_butter_bandpass.bfilter() 2nd argument (f0) can't be converted to float");
  if (f2py_success) {
  /* Processing variable mzer */
    f2py_success = int_from_pyobj(&mzer,mzer_capi,"_butter_bandpass.bfilter() 6th argument (mzer) can't be converted to int");
  if (f2py_success) {
  /* Processing variable fc */
    f2py_success = float_from_pyobj(&fc,fc_capi,"_butter_bandpass.bfilter() 3rd argument (fc) can't be converted to float");
  if (f2py_success) {
  /* Processing variable xr */
  ;
  capi_xr_intent |= F2PY_INTENT_IN;
  capi_xr_tmp = array_from_pyobj(NPY_FLOAT,xr_Dims,xr_Rank,capi_xr_intent,xr_capi);
  if (capi_xr_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(_butter_bandpass_error,"failed in converting 1st argument `xr' of _butter_bandpass.bfilter to C/Fortran array" );
  } else {
    xr = (float *)(capi_xr_tmp->data);

  /* Processing variable dt */
    f2py_success = float_from_pyobj(&dt,dt_capi,"_butter_bandpass.bfilter() 4th argument (dt) can't be converted to float");
  if (f2py_success) {
  /* Processing variable m */
    f2py_success = int_from_pyobj(&m,m_capi,"_butter_bandpass.bfilter() 5th argument (m) can't be converted to int");
  if (f2py_success) {
  /* Processing variable ermx */
  /* Processing variable n */
  if (n_capi == Py_None) n = len(xr); else
    f2py_success = int_from_pyobj(&n,n_capi,"_butter_bandpass.bfilter() 1st keyword (n) can't be converted to int");
  if (f2py_success) {
  CHECKSCALAR(len(xr)>=n,"len(xr)>=n","1st keyword n","bfilter:n=%d",n) {
  /* Processing variable yr */
  yr_Dims[0]=n;
  capi_yr_intent |= F2PY_INTENT_OUT|F2PY_INTENT_HIDE;
  capi_yr_tmp = array_from_pyobj(NPY_FLOAT,yr_Dims,yr_Rank,capi_yr_intent,Py_None);
  if (capi_yr_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(_butter_bandpass_error,"failed in converting hidden `yr' of _butter_bandpass.bfilter to C/Fortran array" );
  } else {
    yr = (float *)(capi_yr_tmp->data);

  /* Processing variable er */
  er_Dims[0]=n;
  capi_er_intent |= F2PY_INTENT_OUT|F2PY_INTENT_HIDE;
  capi_er_tmp = array_from_pyobj(NPY_FLOAT,er_Dims,er_Rank,capi_er_intent,Py_None);
  if (capi_er_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(_butter_bandpass_error,"failed in converting hidden `er' of _butter_bandpass.bfilter to C/Fortran array" );
  } else {
    er = (float *)(capi_er_tmp->data);

/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_call_clock();
#endif
/*callfortranroutine*/
        (*f2py_func)(xr,yr,er,&ermx,&f0,&fc,&dt,&m,&n,&mzer);
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
    capi_buildvalue = Py_BuildValue("NNf",capi_yr_tmp,capi_er_tmp,ermx);
/*closepyobjfrom*/
/*end of closepyobjfrom*/
    } /*if (f2py_success) after callfortranroutine*/
/*cleanupfrompyobj*/
  }  /*if (capi_er_tmp == NULL) ... else of er*/
  /* End of cleaning variable er */
  }  /*if (capi_yr_tmp == NULL) ... else of yr*/
  /* End of cleaning variable yr */
  } /*CHECKSCALAR(len(xr)>=n)*/
  } /*if (f2py_success) of n*/
  /* End of cleaning variable n */
  /* End of cleaning variable ermx */
  } /*if (f2py_success) of m*/
  /* End of cleaning variable m */
  } /*if (f2py_success) of dt*/
  /* End of cleaning variable dt */
  if((PyObject *)capi_xr_tmp!=xr_capi) {
    Py_XDECREF(capi_xr_tmp); }
  }  /*if (capi_xr_tmp == NULL) ... else of xr*/
  /* End of cleaning variable xr */
  } /*if (f2py_success) of fc*/
  /* End of cleaning variable fc */
  } /*if (f2py_success) of mzer*/
  /* End of cleaning variable mzer */
  } /*if (f2py_success) of f0*/
  /* End of cleaning variable f0 */
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
/******************************* end of bfilter *******************************/
/*eof body*/

/******************* See f2py2e/f90mod_rules.py: buildhooks *******************/
/*need_f90modhooks*/

/************** See f2py2e/rules.py: module_rules['modulebody'] **************/

/******************* See f2py2e/common_rules.py: buildhooks *******************/

/*need_commonhooks*/

/**************************** See f2py2e/rules.py ****************************/

static FortranDataDef f2py_routine_defs[] = {
  {"bfilter",-1,{{-1}},0,(char *)F_FUNC(bfilter,BFILTER),(f2py_init_func)f2py_rout__butter_bandpass_bfilter,doc_f2py_rout__butter_bandpass_bfilter},

/*eof routine_defs*/
  {NULL}
};

static PyMethodDef f2py_module_methods[] = {

  {NULL,NULL}
};

#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef moduledef = {
  PyModuleDef_HEAD_INIT,
  "_butter_bandpass",
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
PyMODINIT_FUNC PyInit__butter_bandpass(void) {
#else
#define RETVAL
PyMODINIT_FUNC init_butter_bandpass(void) {
#endif
  int i;
  PyObject *m,*d, *s;
#if PY_VERSION_HEX >= 0x03000000
  m = _butter_bandpass_module = PyModule_Create(&moduledef);
#else
  m = _butter_bandpass_module = Py_InitModule("_butter_bandpass", f2py_module_methods);
#endif
  Py_TYPE(&PyFortran_Type) = &PyType_Type;
  import_array();
  if (PyErr_Occurred())
    {PyErr_SetString(PyExc_ImportError, "can't initialize module _butter_bandpass (failed to import numpy)"); return RETVAL;}
  d = PyModule_GetDict(m);
  s = PyString_FromString("$Revision: $");
  PyDict_SetItemString(d, "__version__", s);
#if PY_VERSION_HEX >= 0x03000000
  s = PyUnicode_FromString(
#else
  s = PyString_FromString(
#endif
    "This module '_butter_bandpass' is auto-generated with f2py (version:2).\nFunctions:\n"
"  yr,er,ermx = bfilter(xr,f0,fc,dt,m,mzer,n=len(xr))\n"
".");
  PyDict_SetItemString(d, "__doc__", s);
  _butter_bandpass_error = PyErr_NewException ("_butter_bandpass.error", NULL, NULL);
  Py_DECREF(s);
  for(i=0;f2py_routine_defs[i].name!=NULL;i++)
    PyDict_SetItemString(d, f2py_routine_defs[i].name,PyFortranObject_NewAsAttr(&f2py_routine_defs[i]));

/*eof initf2pywraphooks*/
/*eof initf90modhooks*/

/*eof initcommonhooks*/


#ifdef F2PY_REPORT_ATEXIT
  if (! PyErr_Occurred())
    on_exit(f2py_report_on_exit,(void*)"_butter_bandpass");
#endif

  return RETVAL;
}
#ifdef __cplusplus
}
#endif