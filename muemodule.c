#include <Python.h>

#include "mue.h"

static PyObject *mue_getpowhash(PyObject *self, PyObject *args)
{
    char *output;
    PyObject *value;
#if PY_MAJOR_VERSION >= 3
    PyBytesObject *input;
#else
    PyStringObject *input;
#endif
    if (!PyArg_ParseTuple(args, "S", &input))
        return NULL;
    Py_INCREF(input);
    output = PyMem_Malloc(32);

#if PY_MAJOR_VERSION >= 3
    mue_hash((char *)PyBytes_AsString((PyObject*) input), output);
#else
    mue_hash((char *)PyString_AsString((PyObject*) input), output);
#endif
    Py_DECREF(input);
#if PY_MAJOR_VERSION >= 3
    value = Py_BuildValue("y#", output, 32);
#else
    value = Py_BuildValue("s#", output, 32);
#endif
    PyMem_Free(output);
    return value;
}

static PyMethodDef MueMethods[] = {
    { "getPoWHash", mue_getpowhash, METH_VARARGS, "Returns the proof of work hash using mue hash" },
    { NULL, NULL, 0, NULL }
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef MueModule = {
    PyModuleDef_HEAD_INIT,
    "mue_hash",
    "...",
    -1,
    MueMethods
};

PyMODINIT_FUNC PyInit_mue_hash(void) {
    return PyModule_Create(&MueModule);
}

#else

PyMODINIT_FUNC initmue_hash(void) {
    (void) Py_InitModule("mue_hash", MueMethods);
}
#endif
