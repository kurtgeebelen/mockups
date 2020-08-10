#include "mex.h"

int mxAddField(mxArray *, const char *) {}
char *mxArrayToString(const mxArray *) {}
mxArray *mxCreateCellMatrix(mwSize, mwSize) {}
mxArray *mxCreateCharMatrixFromStrings(mwSize, const char **) {}
mxArray *mxCreateDoubleMatrix(mwSize, mwSize, mxComplexity) {}
mxArray *mxCreateDoubleScalar(double) {}
mxArray *mxCreateLogicalMatrix(mwSize, mwSize) {}
mxArray *mxCreateLogicalScalar(bool) {}
mxArray *mxCreateNumericArray(mwSize, const mwSize *, mxClassID, mxComplexity) {}
mxArray *mxCreateNumericMatrix(mwSize, mwSize, mxClassID, mxComplexity) {}
mxArray *mxCreateSparse(mwSize, mwSize, mwSize, mxComplexity) {}
mxArray *mxCreateString(const char *) {}
mxArray *mxCreateStructMatrix(mwSize, mwSize, int, const char **) {}
void mxDestroyArray(mxArray *) {}
mxArray *mxGetCell(const mxArray *, mwIndex) {}
mxChar *mxGetChars(const mxArray *) {}
mxClassID mxGetClassID(const mxArray *) {}
void *mxGetData(const mxArray *) {}
const mwSize *mxGetDimensions(const mxArray *) {}
mxArray *mxGetField(const mxArray *, mwIndex, const char *) {}
mxArray *mxGetFieldByNumber(const mxArray *, mwIndex, int) {}
const char *mxGetFieldNameByNumber(const mxArray *, int) {}
mwIndex *mxGetIr(const mxArray *) {}
mwIndex *mxGetJc(const mxArray *) {}
size_t mxGetN(const mxArray *) {}
size_t mxGetM(const mxArray *) {}
mwSize mxGetNumberOfDimensions(const mxArray *) {}
mwSize mxGetNumberOfElements(const mxArray *) {}
int mxGetNumberOfFields(const mxArray *) {}
mxArray * mxGetProperty(const mxArray *, const mwIndex, const char *) {}
double mxGetScalar(const mxArray *) {}
int mxGetString(const mxArray *, char *, mwSize) {}
bool mxIsCell(const mxArray *) {}
bool mxIsChar(const mxArray *) {}
bool mxIsComplex(const mxArray *) {}
bool mxIsDouble(const mxArray *) {}
bool mxIsLogical(const mxArray *) {}
bool mxIsLogicalScalar(const mxArray *) {}
bool mxIsLogicalScalarTrue(const mxArray *) {}
bool mxIsNumeric(const mxArray *) {}
bool mxIsSparse(const mxArray *) {}
bool mxIsStruct(const mxArray *) {}
void mxSetCell(mxArray *, mwIndex, mxArray *) {}
void mxSetField(mxArray *, mwIndex, const char *, mxArray *) {}
void mxSetProperty(mxArray *, mwIndex, const char *, const mxArray *) {}
void mxSetFieldByNumber(mxArray *, mwIndex, int, mxArray *) {}
