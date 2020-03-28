
// Assignment2View.h : interface of the CAssignment2View class
//

#pragma once


class CAssignment2View : public CView
{
protected: // create from serialization only
	CAssignment2View() noexcept;
	DECLARE_DYNCREATE(CAssignment2View)

// Attributes
public:
	CAssignment2Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CAssignment2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Assignment2View.cpp
inline CAssignment2Doc* CAssignment2View::GetDocument() const
   { return reinterpret_cast<CAssignment2Doc*>(m_pDocument); }
#endif

