#include <MatlabEnginePub/CMatlab.h>

namespace MatlabEngine
{
	CMatlab::CMatlab()
	{

	}

	mxArray * CMatlab::createString(const std::string str)
	{
		return mxCreateString(str.c_str());
	}

	mxArray * CMatlab::createCharArray(size_t ndim, size_t * dims)
	{
		return mxCreateCharArray(ndim, dims);
	}

	mxArray * CMatlab::createDoubleScalar(double value)
	{
		return mxCreateDoubleScalar(value);
	}

	mxArray * CMatlab::createDoubleMatrix(size_t m, size_t n, int flag)
	{
		return mxCreateDoubleMatrix(m, n, (mxComplexity)flag);
	}

	mxArray * CMatlab::createCellMatrix(size_t row, size_t col)
	{
		return mxCreateCellMatrix(row, col);
	}

	mxArray * CMatlab::createCellArray(size_t ndim, const size_t * dims)
	{
		return mxCreateCellArray(ndim, dims);
	}

	mxArray * CMatlab::createStructArray(size_t ndim, const size_t * dims, int nfields, const char ** fieldnames)
	{
		return mxCreateStructArray(ndim, dims, nfields, fieldnames);
	}

	mxArray * CMatlab::createStructMatrix(size_t m, size_t n, int nfields, const char ** fieldnames)
	{
		return mxCreateStructMatrix(m, n, nfields, fieldnames);
	}

	mxArray * CMatlab::duplicateArray(mxArray * mx)
	{
		return mxDuplicateArray(mx);
	}

	void CMatlab::setData(mxArray * mx, void * newdata)
	{
		mxSetData(mx, newdata);
	}

	void CMatlab::setCell(mxArray * mx, size_t i, mxArray * value)
	{
		mxSetCell(mx, i, value);
	}

	void CMatlab::setFiled(mxArray * mx, size_t i, const char * fieldname, mxArray * value)
	{
		mxSetField(mx, i, fieldname, value);
	}

	void CMatlab::setFieldByNumber(mxArray * mx, size_t i, int fieldnum, mxArray * value)
	{
		mxSetFieldByNumber(mx, i, fieldnum, value);
	}

	void CMatlab::setRowDims(mxArray * mx, size_t m)
	{
		mxSetM(mx, m);
	}

	void CMatlab::setColumnDims(mxArray * mx, size_t n)
	{
		mxSetN(mx, n);
	}

	void CMatlab::setDims(mxArray * mx, const size_t *m, const size_t n)
	{
		mxSetDimensions(mx, m, n);
	}

	float * CMatlab::getPReal(mxArray * mx)
	{
		return (float *)mxGetPr(mx);
	}

	void CMatlab::destroy(mxArray * mx)
	{
		mxDestroyArray(mx);
	}

	void CMatlab::free(void *ptr)
	{
		mxFree(ptr);
	}

	bool CMatlab::isEmpty(mxArray * mx)
	{
		return mxIsEmpty(mx);
	}

}