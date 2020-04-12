
// Assignment2View.cpp : implementation of the CAssignment2View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Assignment2.h"
#endif

#include "Assignment2Doc.h"
#include "Assignment2View.h"

//////////////////////////////////////////////////////////////////
////////////////////// User defined header files//////////////////
//////////////////////////////////////////////////////////////////
#include "myClasses.h"
#include "myPoint.h"
#include "myCircle.h"
#include "myRectangle.h"
#include "myTriangle.h"
#include "myShape.h"
#include "myPattern.h"
#include<iostream>
#include<string>
//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAssignment2View

IMPLEMENT_DYNCREATE(CAssignment2View, CView)

BEGIN_MESSAGE_MAP(CAssignment2View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CAssignment2View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CAssignment2View construction/destruction

CAssignment2View::CAssignment2View() noexcept
{
	// TODO: add construction code here

}

CAssignment2View::~CAssignment2View()
{
}

BOOL CAssignment2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CAssignment2View drawing

////////////////////////////////////////////////////////////////////////////////////
void CAssignment2View::OnDraw(CDC* pDC)
{
	CAssignment2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	// Drawing area ~1500 x ~840 when window maximized, toolbars open
	
	myPoint A(900, 100);
	myPoint B(850, 200);
	myPoint C(1000, 100);
	/*myTriangle triA(A,B,C);

	myCircle circA(200,200,10);
	myRectangle rectA(myPoint(300, 300), myPoint(600, 600));*/
	/*triA.draw(pDC);
	triA.centroid.show(pDC);

	myPoint u(-300, 300);
	triA.translate(u);
	triA.draw(pDC);
	triA.centroid.show(pDC);*/

	myPattern pattA("pattA");
	pattA.addShape(new myTriangle(A, B, C));
	pattA.addShape(new myCircle(200, 200, 10));
	pattA.addShape(new myRectangle(myPoint(300, 300), myPoint(600, 600)));
	pattA.draw(pDC);
}
///////////////////////////////////////////////////////////////////////////////////

// CAssignment2View printing


void CAssignment2View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CAssignment2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CAssignment2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CAssignment2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CAssignment2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CAssignment2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CAssignment2View diagnostics

#ifdef _DEBUG
void CAssignment2View::AssertValid() const
{
	CView::AssertValid();
}

void CAssignment2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CAssignment2Doc* CAssignment2View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAssignment2Doc)));
	return (CAssignment2Doc*)m_pDocument;
}
#endif //_DEBUG


// CAssignment2View message handlers
