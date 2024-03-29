/*
** libproj -- library of cartographic projections
**
** Copyright (c) 2003   Gerald I. Evenden
*/
static const char
LIBPROJ_ID[] = "$Id: PJ_lagrng.c,v 2.2 2005/03/07 18:56:18 gie Exp gie $";
/*
** Permission is hereby granted, free of charge, to any person obtaining
** a copy of this software and associated documentation files (the
** "Software"), to deal in the Software without restriction, including
** without limitation the rights to use, copy, modify, merge, publish,
** distribute, sublicense, and/or sell copies of the Software, and to
** permit persons to whom the Software is furnished to do so, subject to
** the following conditions:
**
** The above copyright notice and this permission notice shall be
** included in all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
** EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
** MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
** IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
** CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
** TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
** SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#define PROJ_PARMS__ \
	double	hrw; \
	double	rw; \
	double	a1;
#define TOL	1e-10
#define PJ_LIB__
#include	<lib_proj.h>
PROJ_HEAD(lagrng, "Lagrange") "\n\tMisc Sph, no inv.\n\tW=";
FORWARD(s_forward); /* spheroid */
	double v, c;

	if (fabs(fabs(lp.phi) - HALFPI) < TOL) {
		xy.x = 0;
		xy.y = lp.phi < 0 ? -2. : 2.;
	} else {
		lp.phi = sin(lp.phi);
		v = P->a1 * pow((1. + lp.phi)/(1. - lp.phi), P->hrw);
		if ((c = 0.5 * (v + 1./v) + cos(lp.lam *= P->rw)) < TOL)
			F_ERROR;
		xy.x = 2. * sin(lp.lam) / c;
		xy.y = (v - 1./v) / c;
	}
	return (xy);
}
FREEUP; if (P) free(P); }
ENTRY0(lagrng)
	double phi1;

	if (pj_param(P->params, "tW").i == 0)
		P->rw = 2.0;
	else if ((P->rw = pj_param(P->params, "dW").f) < 1.0) E_ERROR(-27);
	P->hrw = 0.5 * (P->rw = 1. / P->rw);
	phi1 = pj_param(P->params, "rlat_1").f;
	if (fabs(fabs(phi1 = sin(phi1)) - 1.) < TOL) E_ERROR(-22);
	P->a1 = pow((1. - phi1)/(1. + phi1), P->hrw);
	P->es = 0.; P->fwd = s_forward;
ENDENTRY(P)
/*
** $Log: PJ_lagrng.c,v $
** Revision 2.2  2005/03/07 18:56:18  gie
** default value of 2. for W option and W must be >= 1.
**
** Revision 2.1  2003/03/28 01:46:39  gie
** Initial
**
*/
