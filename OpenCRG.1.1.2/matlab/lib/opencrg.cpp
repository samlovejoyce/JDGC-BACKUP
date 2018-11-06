//
// MATLAB Compiler: 6.6 (R2018a)
// Date: Fri Jul 27 10:56:20 2018
// Arguments:
// "-B""macro_default""-W""cpplib:opencrg""-T""link:lib""copy_ax2fig.m""crg_appe
// nd.m""crg_b2z.m""crg_check.m""crg_check_data.m""crg_check_head.m""crg_check_m
// ods.m""crg_check_opts.m""crg_check_single.m""crg_check_uv_descript.m""crg_cut
// _iuiv.m""crg_eval_u2crv.m""crg_eval_u2phi.m""crg_eval_uv2iuiv.m""crg_eval_uv2
// xy.m""crg_eval_uv2z.m""crg_eval_xy2uv.m""crg_eval_xy2z.m""crg_ext_banking.m""
// crg_ext_slope.m""crg_figure.m""crg_filter.m""crg_flip.m""crg_gen_csb2crg0.m""
// crg_gen_ppxy2phi.m""crg_gen_pxy2ppxy.m""crg_isequal.m""crg_limiter.m""crg_map
// _uv2uv.m""crg_map_xy2xy.m""crg_mods.m""crg_peakfinder.m""crg_perform2surface.
// m""crg_plot_elgrid_cross_sect.m""crg_plot_elgrid_limits.m""crg_plot_elgrid_lo
// ng_sect.m""crg_plot_elgrid_uvz_map.m""crg_plot_elgrid_xyz_map.m""crg_plot_ref
// line_curvature.m""crg_plot_refline_elevation.m""crg_plot_refline_heading.m""c
// rg_plot_refline_slope_bank.m""crg_plot_refline_xy_map_and_curv.m""crg_plot_re
// fline_xy_overview_map.m""crg_plot_refline_xyz_map.m""crg_plot_refpnt_distance
// s.m""crg_plot_road_uv2uvz_map.m""crg_plot_road_uv2xyz_map.m""crg_plot_road_uv
// z_map.m""crg_plot_road_xyz_map.m""crg_read.m""crg_rerender.m""crg_s2z.m""crg_
// separate_sb.m""crg_show.m""crg_show_elgrid_cuts_and_limits.m""crg_show_elgrid
// _surface.m""crg_show_info.m""crg_show_isequal.m""crg_show_peaks.m""crg_show_r
// efline_elevation.m""crg_show_refline_map.m""crg_show_refpnts_and_refline.m""c
// rg_show_road_surface.m""crg_show_road_uv2surface.m""crg_single.m""crg_surf.m"
// "crg_wgs84_crg2html.m""crg_wgs84_dist.m""crg_wgs84_invdist.m""crg_wgs84_seten
// d.m""crg_wgs84_wgs2url.m""crg_wgs84_wgsxy2wgs.m""crg_wgs84_xy2wgs.m""crg_wrap
// .m""crg_write.m""ipl_read.m""ipl_write.m""map_wgs2html.m""sdf_add.m""sdf_cut.
// m""smooth_firfilt.m""str_num2strn.m"
//

#include <stdio.h>
#define EXPORTING_opencrg 1
#include "opencrg.h"

static HMCRINSTANCE _mcr_inst = NULL;

#if defined( _MSC_VER) || defined(__LCC__) || defined(__MINGW64__)
#ifdef __LCC__
#undef EXTERN_C
#endif
#include <windows.h>

static char path_to_dll[_MAX_PATH];

BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, void *pv)
{
    if (dwReason == DLL_PROCESS_ATTACH)
    {
        if (GetModuleFileName(hInstance, path_to_dll, _MAX_PATH) == 0)
            return FALSE;
    }
    else if (dwReason == DLL_PROCESS_DETACH)
    {
    }
    return TRUE;
}
#endif
#ifdef __cplusplus
extern "C" {
#endif

static int mclDefaultPrintHandler(const char *s)
{
    return mclWrite(1 /* stdout */, s, sizeof(char)*strlen(s));
}

#ifdef __cplusplus
} /* End extern "C" block */
#endif

#ifdef __cplusplus
extern "C" {
#endif

static int mclDefaultErrorHandler(const char *s)
{
    int written = 0;
    size_t len = 0;
    len = strlen(s);
    written = mclWrite(2 /* stderr */, s, sizeof(char)*len);
    if (len > 0 && s[ len-1 ] != '\n')
        written += mclWrite(2 /* stderr */, "\n", sizeof(char));
    return written;
}

#ifdef __cplusplus
} /* End extern "C" block */
#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_opencrg_C_API
#define LIB_opencrg_C_API /* No special import/export declaration */
#endif

LIB_opencrg_C_API 
bool MW_CALL_CONV opencrgInitializeWithHandlers(
    mclOutputHandlerFcn error_handler,
    mclOutputHandlerFcn print_handler)
{
    int bResult = 0;
    if (_mcr_inst != NULL)
        return true;
    if (!mclmcrInitialize())
        return false;
    if (!GetModuleFileName(GetModuleHandle("opencrg"), path_to_dll, _MAX_PATH))
        return false;
    {
        mclCtfStream ctfStream = 
            mclGetEmbeddedCtfStream(path_to_dll);
        if (ctfStream) {
            bResult = mclInitializeComponentInstanceEmbedded(&_mcr_inst,
                                                             error_handler, 
                                                             print_handler,
                                                             ctfStream);
            mclDestroyStream(ctfStream);
        } else {
            bResult = 0;
        }
    }  
    if (!bResult)
    return false;
    return true;
}

LIB_opencrg_C_API 
bool MW_CALL_CONV opencrgInitialize(void)
{
    return opencrgInitializeWithHandlers(mclDefaultErrorHandler, mclDefaultPrintHandler);
}

LIB_opencrg_C_API 
void MW_CALL_CONV opencrgTerminate(void)
{
    if (_mcr_inst != NULL)
        mclTerminateInstance(&_mcr_inst);
}

LIB_opencrg_C_API 
void MW_CALL_CONV opencrgPrintStackTrace(void) 
{
    char** stackTrace;
    int stackDepth = mclGetStackTrace(&stackTrace);
    int i;
    for(i=0; i<stackDepth; i++)
    {
        mclWrite(2 /* stderr */, stackTrace[i], sizeof(char)*strlen(stackTrace[i]));
        mclWrite(2 /* stderr */, "\n", sizeof(char)*strlen("\n"));
    }
    mclFreeStackTrace(&stackTrace, stackDepth);
}


LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCopy_ax2fig(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "copy_ax2fig", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_append(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "crg_append", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_b2z(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "crg_b2z", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_check(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "crg_check", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_check_data(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "crg_check_data", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_check_head(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "crg_check_head", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_check_mods(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "crg_check_mods", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_check_opts(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "crg_check_opts", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_check_single(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                      *prhs[])
{
    return mclFeval(_mcr_inst, "crg_check_single", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_check_uv_descript(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                           *prhs[])
{
    return mclFeval(_mcr_inst, "crg_check_uv_descript", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_cut_iuiv(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "crg_cut_iuiv", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_eval_u2crv(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "crg_eval_u2crv", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_eval_u2phi(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "crg_eval_u2phi", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_eval_uv2iuiv(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                      *prhs[])
{
    return mclFeval(_mcr_inst, "crg_eval_uv2iuiv", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_eval_uv2xy(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "crg_eval_uv2xy", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_eval_uv2z(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "crg_eval_uv2z", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_eval_xy2uv(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "crg_eval_xy2uv", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_eval_xy2z(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "crg_eval_xy2z", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_ext_banking(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "crg_ext_banking", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_ext_slope(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "crg_ext_slope", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_figure(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "crg_figure", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_filter(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "crg_filter", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_flip(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "crg_flip", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_gen_csb2crg0(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                      *prhs[])
{
    return mclFeval(_mcr_inst, "crg_gen_csb2crg0", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_gen_ppxy2phi(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                      *prhs[])
{
    return mclFeval(_mcr_inst, "crg_gen_ppxy2phi", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_gen_pxy2ppxy(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                      *prhs[])
{
    return mclFeval(_mcr_inst, "crg_gen_pxy2ppxy", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_isequal(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "crg_isequal", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_limiter(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "crg_limiter", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_map_uv2uv(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "crg_map_uv2uv", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_map_xy2xy(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "crg_map_xy2xy", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_mods(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "crg_mods", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_peakfinder(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "crg_peakfinder", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_perform2surface(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                         *prhs[])
{
    return mclFeval(_mcr_inst, "crg_perform2surface", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_plot_elgrid_cross_sect(int nlhs, mxArray *plhs[], int nrhs, 
                                                mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "crg_plot_elgrid_cross_sect", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_plot_elgrid_limits(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                            *prhs[])
{
    return mclFeval(_mcr_inst, "crg_plot_elgrid_limits", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_plot_elgrid_long_sect(int nlhs, mxArray *plhs[], int nrhs, 
                                               mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "crg_plot_elgrid_long_sect", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_plot_elgrid_uvz_map(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                             *prhs[])
{
    return mclFeval(_mcr_inst, "crg_plot_elgrid_uvz_map", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_plot_elgrid_xyz_map(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                             *prhs[])
{
    return mclFeval(_mcr_inst, "crg_plot_elgrid_xyz_map", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_plot_refline_curvature(int nlhs, mxArray *plhs[], int nrhs, 
                                                mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "crg_plot_refline_curvature", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_plot_refline_elevation(int nlhs, mxArray *plhs[], int nrhs, 
                                                mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "crg_plot_refline_elevation", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_plot_refline_heading(int nlhs, mxArray *plhs[], int nrhs, 
                                              mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "crg_plot_refline_heading", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_plot_refline_slope_bank(int nlhs, mxArray *plhs[], int nrhs, 
                                                 mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "crg_plot_refline_slope_bank", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_plot_refline_xy_map_and_curv(int nlhs, mxArray *plhs[], int 
                                                      nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "crg_plot_refline_xy_map_and_curv", nlhs, plhs, nrhs, 
                  prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_plot_refline_xy_overview_map(int nlhs, mxArray *plhs[], int 
                                                      nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "crg_plot_refline_xy_overview_map", nlhs, plhs, nrhs, 
                  prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_plot_refline_xyz_map(int nlhs, mxArray *plhs[], int nrhs, 
                                              mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "crg_plot_refline_xyz_map", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_plot_refpnt_distances(int nlhs, mxArray *plhs[], int nrhs, 
                                               mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "crg_plot_refpnt_distances", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_plot_road_uv2uvz_map(int nlhs, mxArray *plhs[], int nrhs, 
                                              mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "crg_plot_road_uv2uvz_map", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_plot_road_uv2xyz_map(int nlhs, mxArray *plhs[], int nrhs, 
                                              mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "crg_plot_road_uv2xyz_map", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_plot_road_uvz_map(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                           *prhs[])
{
    return mclFeval(_mcr_inst, "crg_plot_road_uvz_map", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_plot_road_xyz_map(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                           *prhs[])
{
    return mclFeval(_mcr_inst, "crg_plot_road_xyz_map", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_read(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "crg_read", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_rerender(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "crg_rerender", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_s2z(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "crg_s2z", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_separate_sb(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "crg_separate_sb", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_show(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "crg_show", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_show_elgrid_cuts_and_limits(int nlhs, mxArray *plhs[], int nrhs, 
                                                     mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "crg_show_elgrid_cuts_and_limits", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_show_elgrid_surface(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                             *prhs[])
{
    return mclFeval(_mcr_inst, "crg_show_elgrid_surface", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_show_info(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "crg_show_info", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_show_isequal(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                      *prhs[])
{
    return mclFeval(_mcr_inst, "crg_show_isequal", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_show_peaks(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "crg_show_peaks", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_show_refline_elevation(int nlhs, mxArray *plhs[], int nrhs, 
                                                mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "crg_show_refline_elevation", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_show_refline_map(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                          *prhs[])
{
    return mclFeval(_mcr_inst, "crg_show_refline_map", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_show_refpnts_and_refline(int nlhs, mxArray *plhs[], int nrhs, 
                                                  mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "crg_show_refpnts_and_refline", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_show_road_surface(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                           *prhs[])
{
    return mclFeval(_mcr_inst, "crg_show_road_surface", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_show_road_uv2surface(int nlhs, mxArray *plhs[], int nrhs, 
                                              mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "crg_show_road_uv2surface", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_single(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "crg_single", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_surf(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "crg_surf", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_wgs84_crg2html(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                        *prhs[])
{
    return mclFeval(_mcr_inst, "crg_wgs84_crg2html", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_wgs84_dist(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "crg_wgs84_dist", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_wgs84_invdist(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                       *prhs[])
{
    return mclFeval(_mcr_inst, "crg_wgs84_invdist", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_wgs84_setend(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                      *prhs[])
{
    return mclFeval(_mcr_inst, "crg_wgs84_setend", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_wgs84_wgs2url(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                       *prhs[])
{
    return mclFeval(_mcr_inst, "crg_wgs84_wgs2url", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_wgs84_wgsxy2wgs(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                         *prhs[])
{
    return mclFeval(_mcr_inst, "crg_wgs84_wgsxy2wgs", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_wgs84_xy2wgs(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                      *prhs[])
{
    return mclFeval(_mcr_inst, "crg_wgs84_xy2wgs", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_wrap(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "crg_wrap", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxCrg_write(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "crg_write", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxIpl_read(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "ipl_read", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxIpl_write(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "ipl_write", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxMap_wgs2html(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "map_wgs2html", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxSdf_add(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "sdf_add", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxSdf_cut(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "sdf_cut", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxSmooth_firfilt(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "smooth_firfilt", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_C_API 
bool MW_CALL_CONV mlxStr_num2strn(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "str_num2strn", nlhs, plhs, nrhs, prhs);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV copy_ax2fig()
{
    mclcppMlfFeval(_mcr_inst, "copy_ax2fig", 0, 0, 0);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_append(int nargout, mwArray& data, mwArray& roff2, const mwArray& 
                             data1, const mwArray& data2)
{
    mclcppMlfFeval(_mcr_inst, "crg_append", nargout, 2, 2, &data, &roff2, &data1, &data2);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_b2z(int nargout, mwArray& data, const mwArray& data_in1, const 
                          mwArray& b)
{
    mclcppMlfFeval(_mcr_inst, "crg_b2z", nargout, 1, 2, &data, &data_in1, &b);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_check(int nargout, mwArray& data, const mwArray& data_in1)
{
    mclcppMlfFeval(_mcr_inst, "crg_check", nargout, 1, 1, &data, &data_in1);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_check_data(int nargout, mwArray& data, const mwArray& data_in1)
{
    mclcppMlfFeval(_mcr_inst, "crg_check_data", nargout, 1, 1, &data, &data_in1);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_check_head(int nargout, mwArray& data, const mwArray& data_in1)
{
    mclcppMlfFeval(_mcr_inst, "crg_check_head", nargout, 1, 1, &data, &data_in1);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_check_mods(int nargout, mwArray& data, const mwArray& data_in1)
{
    mclcppMlfFeval(_mcr_inst, "crg_check_mods", nargout, 1, 1, &data, &data_in1);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_check_opts(int nargout, mwArray& data, const mwArray& data_in1)
{
    mclcppMlfFeval(_mcr_inst, "crg_check_opts", nargout, 1, 1, &data, &data_in1);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_check_single(int nargout, mwArray& data, const mwArray& data_in1)
{
    mclcppMlfFeval(_mcr_inst, "crg_check_single", nargout, 1, 1, &data, &data_in1);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_check_uv_descript(int nargout, mwArray& v, const mwArray& 
                                        uv_descript, const mwArray& posmode)
{
    mclcppMlfFeval(_mcr_inst, "crg_check_uv_descript", nargout, 1, 2, &v, &uv_descript, &posmode);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_cut_iuiv(int nargout, mwArray& data, const mwArray& data_in1, const 
                               mwArray& iu, const mwArray& iv)
{
    mclcppMlfFeval(_mcr_inst, "crg_cut_iuiv", nargout, 1, 3, &data, &data_in1, &iu, &iv);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_eval_u2crv(int nargout, mwArray& crv, mwArray& data, const mwArray& 
                                 data_in1, const mwArray& pu)
{
    mclcppMlfFeval(_mcr_inst, "crg_eval_u2crv", nargout, 2, 2, &crv, &data, &data_in1, &pu);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_eval_u2phi(int nargout, mwArray& phi, mwArray& data, const mwArray& 
                                 data_in1, const mwArray& pu)
{
    mclcppMlfFeval(_mcr_inst, "crg_eval_u2phi", nargout, 2, 2, &phi, &data, &data_in1, &pu);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_eval_uv2iuiv(int nargout, mwArray& iu, mwArray& iv, const mwArray& 
                                   data, const mwArray& u, const mwArray& v)
{
    mclcppMlfFeval(_mcr_inst, "crg_eval_uv2iuiv", nargout, 2, 3, &iu, &iv, &data, &u, &v);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_eval_uv2xy(int nargout, mwArray& pxy, mwArray& data, const mwArray& 
                                 data_in1, const mwArray& puv)
{
    mclcppMlfFeval(_mcr_inst, "crg_eval_uv2xy", nargout, 2, 2, &pxy, &data, &data_in1, &puv);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_eval_uv2z(int nargout, mwArray& pz, mwArray& data, const mwArray& 
                                data_in1, const mwArray& puv)
{
    mclcppMlfFeval(_mcr_inst, "crg_eval_uv2z", nargout, 2, 2, &pz, &data, &data_in1, &puv);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_eval_xy2uv(int nargout, mwArray& puv, mwArray& data, const mwArray& 
                                 data_in1, const mwArray& pxy)
{
    mclcppMlfFeval(_mcr_inst, "crg_eval_xy2uv", nargout, 2, 2, &puv, &data, &data_in1, &pxy);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_eval_xy2z(int nargout, mwArray& pz, mwArray& data, const mwArray& 
                                data_in1, const mwArray& pxy)
{
    mclcppMlfFeval(_mcr_inst, "crg_eval_xy2z", nargout, 2, 2, &pz, &data, &data_in1, &pxy);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_ext_banking(int nargout, mwArray& data, const mwArray& data_in1, 
                                  const mwArray& pp)
{
    mclcppMlfFeval(_mcr_inst, "crg_ext_banking", nargout, 1, 2, &data, &data_in1, &pp);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_ext_slope(int nargout, mwArray& data, const mwArray& data_in1, 
                                const mwArray& p)
{
    mclcppMlfFeval(_mcr_inst, "crg_ext_slope", nargout, 1, 2, &data, &data_in1, &p);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_figure(int nargout, mwArray& data, const mwArray& data_in1)
{
    mclcppMlfFeval(_mcr_inst, "crg_figure", nargout, 1, 1, &data, &data_in1);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_filter(int nargout, mwArray& data, const mwArray& data_in1, const 
                             mwArray& iu, const mwArray& iv, const mwArray& fm, const 
                             mwArray& mask, const mwArray& wopt)
{
    mclcppMlfFeval(_mcr_inst, "crg_filter", nargout, 1, 6, &data, &data_in1, &iu, &iv, &fm, &mask, &wopt);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_flip(int nargout, mwArray& data, const mwArray& data_in1)
{
    mclcppMlfFeval(_mcr_inst, "crg_flip", nargout, 1, 1, &data, &data_in1);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_gen_csb2crg0(int nargout, mwArray& data, const mwArray& inc, const 
                                   mwArray& u, const mwArray& v, const mwArray& c, const 
                                   mwArray& s, const mwArray& b)
{
    mclcppMlfFeval(_mcr_inst, "crg_gen_csb2crg0", nargout, 1, 6, &data, &inc, &u, &v, &c, &s, &b);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_gen_ppxy2phi(int nargout, mwArray& data, mwArray& err, const 
                                   mwArray& ppxy, const mwArray& uinc, const mwArray& 
                                   opts)
{
    mclcppMlfFeval(_mcr_inst, "crg_gen_ppxy2phi", nargout, 2, 3, &data, &err, &ppxy, &uinc, &opts);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_gen_pxy2ppxy(int nargout, mwArray& ppxy, const mwArray& pxy, const 
                                   mwArray& opts)
{
    mclcppMlfFeval(_mcr_inst, "crg_gen_pxy2ppxy", nargout, 1, 2, &ppxy, &pxy, &opts);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_isequal(int nargout, mwArray& ident, mwArray& dd, const mwArray& 
                              bcrg, const mwArray& acrg)
{
    mclcppMlfFeval(_mcr_inst, "crg_isequal", nargout, 2, 2, &ident, &dd, &bcrg, &acrg);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_limiter(int nargout, mwArray& data, const mwArray& data_in1, const 
                              mwArray& mmlim, const mwArray& iu, const mwArray& iv)
{
    mclcppMlfFeval(_mcr_inst, "crg_limiter", nargout, 1, 4, &data, &data_in1, &mmlim, &iu, &iv);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_map_uv2uv(int nargout, mwArray& data, const mwArray& data_in1, 
                                const mwArray& crg_uv, const mwArray& iu, const mwArray& 
                                iv)
{
    mclcppMlfFeval(_mcr_inst, "crg_map_uv2uv", nargout, 1, 4, &data, &data_in1, &crg_uv, &iu, &iv);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_map_xy2xy(int nargout, mwArray& data, const mwArray& data_in1, 
                                const mwArray& crg_xy, const mwArray& iu, const mwArray& 
                                iv)
{
    mclcppMlfFeval(_mcr_inst, "crg_map_xy2xy", nargout, 1, 4, &data, &data_in1, &crg_xy, &iu, &iv);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_mods(int nargout, mwArray& data, const mwArray& data_in1)
{
    mclcppMlfFeval(_mcr_inst, "crg_mods", nargout, 1, 1, &data, &data_in1);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_peakfinder(int nargout, mwArray& pindex, mwArray& pij, const 
                                 mwArray& data, const mwArray& iu, const mwArray& iv, 
                                 const mwArray& th, const mwArray& ra)
{
    mclcppMlfFeval(_mcr_inst, "crg_peakfinder", nargout, 2, 5, &pindex, &pij, &data, &iu, &iv, &th, &ra);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_perform2surface(int nargout, mwArray& data, const mwArray& 
                                      data_in1, const mwArray& uv_surf, const mwArray& 
                                      oper)
{
    mclcppMlfFeval(_mcr_inst, "crg_perform2surface", nargout, 1, 3, &data, &data_in1, &uv_surf, &oper);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_plot_elgrid_cross_sect(int nargout, mwArray& data, const mwArray& 
                                             data_in1, const mwArray& iu, const mwArray& 
                                             iv)
{
    mclcppMlfFeval(_mcr_inst, "crg_plot_elgrid_cross_sect", nargout, 1, 3, &data, &data_in1, &iu, &iv);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_plot_elgrid_limits(int nargout, mwArray& data, const mwArray& 
                                         data_in1, const mwArray& iu, const mwArray& iv)
{
    mclcppMlfFeval(_mcr_inst, "crg_plot_elgrid_limits", nargout, 1, 3, &data, &data_in1, &iu, &iv);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_plot_elgrid_long_sect(int nargout, mwArray& data, const mwArray& 
                                            data_in1, const mwArray& iu, const mwArray& 
                                            iv)
{
    mclcppMlfFeval(_mcr_inst, "crg_plot_elgrid_long_sect", nargout, 1, 3, &data, &data_in1, &iu, &iv);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_plot_elgrid_uvz_map(int nargout, mwArray& data, const mwArray& 
                                          data_in1, const mwArray& iu, const mwArray& iv)
{
    mclcppMlfFeval(_mcr_inst, "crg_plot_elgrid_uvz_map", nargout, 1, 3, &data, &data_in1, &iu, &iv);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_plot_elgrid_xyz_map(int nargout, mwArray& data, const mwArray& 
                                          data_in1, const mwArray& iu, const mwArray& iv)
{
    mclcppMlfFeval(_mcr_inst, "crg_plot_elgrid_xyz_map", nargout, 1, 3, &data, &data_in1, &iu, &iv);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_plot_refline_curvature(int nargout, mwArray& data, const mwArray& 
                                             data_in1, const mwArray& iu)
{
    mclcppMlfFeval(_mcr_inst, "crg_plot_refline_curvature", nargout, 1, 2, &data, &data_in1, &iu);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_plot_refline_elevation(int nargout, mwArray& data, const mwArray& 
                                             data_in1, const mwArray& iu)
{
    mclcppMlfFeval(_mcr_inst, "crg_plot_refline_elevation", nargout, 1, 2, &data, &data_in1, &iu);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_plot_refline_heading(int nargout, mwArray& data, const mwArray& 
                                           data_in1, const mwArray& iu)
{
    mclcppMlfFeval(_mcr_inst, "crg_plot_refline_heading", nargout, 1, 2, &data, &data_in1, &iu);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_plot_refline_slope_bank(int nargout, mwArray& data, const mwArray& 
                                              data_in1, const mwArray& iu)
{
    mclcppMlfFeval(_mcr_inst, "crg_plot_refline_slope_bank", nargout, 1, 2, &data, &data_in1, &iu);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_plot_refline_xy_map_and_curv(int nargout, mwArray& data, const 
                                                   mwArray& data_in1, const mwArray& iu)
{
    mclcppMlfFeval(_mcr_inst, "crg_plot_refline_xy_map_and_curv", nargout, 1, 2, &data, &data_in1, &iu);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_plot_refline_xy_overview_map(int nargout, mwArray& data, const 
                                                   mwArray& data_in1, const mwArray& iu)
{
    mclcppMlfFeval(_mcr_inst, "crg_plot_refline_xy_overview_map", nargout, 1, 2, &data, &data_in1, &iu);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_plot_refline_xyz_map(int nargout, mwArray& data, const mwArray& 
                                           data_in1, const mwArray& iu)
{
    mclcppMlfFeval(_mcr_inst, "crg_plot_refline_xyz_map", nargout, 1, 2, &data, &data_in1, &iu);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_plot_refpnt_distances(int nargout, mwArray& data, const mwArray& 
                                            data_in1, const mwArray& pxy)
{
    mclcppMlfFeval(_mcr_inst, "crg_plot_refpnt_distances", nargout, 1, 2, &data, &data_in1, &pxy);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_plot_road_uv2uvz_map(int nargout, mwArray& data, const mwArray& 
                                           data_in1, const mwArray& u, const mwArray& v)
{
    mclcppMlfFeval(_mcr_inst, "crg_plot_road_uv2uvz_map", nargout, 1, 3, &data, &data_in1, &u, &v);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_plot_road_uv2xyz_map(int nargout, mwArray& data, const mwArray& 
                                           data_in1, const mwArray& u, const mwArray& v)
{
    mclcppMlfFeval(_mcr_inst, "crg_plot_road_uv2xyz_map", nargout, 1, 3, &data, &data_in1, &u, &v);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_plot_road_uvz_map(int nargout, mwArray& data, const mwArray& 
                                        data_in1, const mwArray& iu, const mwArray& iv)
{
    mclcppMlfFeval(_mcr_inst, "crg_plot_road_uvz_map", nargout, 1, 3, &data, &data_in1, &iu, &iv);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_plot_road_xyz_map(int nargout, mwArray& data, const mwArray& 
                                        data_in1, const mwArray& iu, const mwArray& iv)
{
    mclcppMlfFeval(_mcr_inst, "crg_plot_road_xyz_map", nargout, 1, 3, &data, &data_in1, &iu, &iv);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_read(int nargout, mwArray& data, const mwArray& file)
{
    mclcppMlfFeval(_mcr_inst, "crg_read", nargout, 1, 1, &data, &file);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_rerender(int nargout, mwArray& data, const mwArray& crg, const 
                               mwArray& inc, const mwArray& v)
{
    mclcppMlfFeval(_mcr_inst, "crg_rerender", nargout, 1, 3, &data, &crg, &inc, &v);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_s2z(int nargout, mwArray& data, const mwArray& data_in1, const 
                          mwArray& rz)
{
    mclcppMlfFeval(_mcr_inst, "crg_s2z", nargout, 1, 2, &data, &data_in1, &rz);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_separate_sb(int nargout, mwArray& data, const mwArray& data_in1, 
                                  const mwArray& swlen, const mwArray& bwlen)
{
    mclcppMlfFeval(_mcr_inst, "crg_separate_sb", nargout, 1, 3, &data, &data_in1, &swlen, &bwlen);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_show(int nargout, mwArray& data, const mwArray& data_in1, const 
                           mwArray& iu, const mwArray& iv)
{
    mclcppMlfFeval(_mcr_inst, "crg_show", nargout, 1, 3, &data, &data_in1, &iu, &iv);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_show_elgrid_cuts_and_limits(int nargout, mwArray& data, const 
                                                  mwArray& data_in1, const mwArray& iu, 
                                                  const mwArray& iv)
{
    mclcppMlfFeval(_mcr_inst, "crg_show_elgrid_cuts_and_limits", nargout, 1, 3, &data, &data_in1, &iu, &iv);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_show_elgrid_surface(int nargout, mwArray& data, const mwArray& 
                                          data_in1, const mwArray& iu, const mwArray& iv)
{
    mclcppMlfFeval(_mcr_inst, "crg_show_elgrid_surface", nargout, 1, 3, &data, &data_in1, &iu, &iv);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_show_info(int nargout, mwArray& data, const mwArray& data_in1)
{
    mclcppMlfFeval(_mcr_inst, "crg_show_info", nargout, 1, 1, &data, &data_in1);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_show_isequal(const mwArray& dd, const mwArray& out)
{
    mclcppMlfFeval(_mcr_inst, "crg_show_isequal", 0, 0, 2, &dd, &out);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_show_peaks(int nargout, mwArray& data, const mwArray& data_in1, 
                                 const mwArray& pindex, const mwArray& su, const mwArray& 
                                 sv, const mwArray& iu, const mwArray& iv)
{
    mclcppMlfFeval(_mcr_inst, "crg_show_peaks", nargout, 1, 6, &data, &data_in1, &pindex, &su, &sv, &iu, &iv);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_show_refline_elevation(int nargout, mwArray& data, const mwArray& 
                                             data_in1, const mwArray& iu)
{
    mclcppMlfFeval(_mcr_inst, "crg_show_refline_elevation", nargout, 1, 2, &data, &data_in1, &iu);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_show_refline_map(int nargout, mwArray& data, const mwArray& 
                                       data_in1, const mwArray& iu)
{
    mclcppMlfFeval(_mcr_inst, "crg_show_refline_map", nargout, 1, 2, &data, &data_in1, &iu);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_show_refpnts_and_refline(int nargout, mwArray& data, const mwArray& 
                                               data_in1, const mwArray& pxy)
{
    mclcppMlfFeval(_mcr_inst, "crg_show_refpnts_and_refline", nargout, 1, 2, &data, &data_in1, &pxy);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_show_road_surface(int nargout, mwArray& data, const mwArray& 
                                        data_in1, const mwArray& iu, const mwArray& iv)
{
    mclcppMlfFeval(_mcr_inst, "crg_show_road_surface", nargout, 1, 3, &data, &data_in1, &iu, &iv);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_show_road_uv2surface(int nargout, mwArray& data, const mwArray& 
                                           data_in1, const mwArray& u, const mwArray& v)
{
    mclcppMlfFeval(_mcr_inst, "crg_show_road_uv2surface", nargout, 1, 3, &data, &data_in1, &u, &v);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_single(int nargout, mwArray& data, const mwArray& data_in1)
{
    mclcppMlfFeval(_mcr_inst, "crg_single", nargout, 1, 1, &data, &data_in1);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_surf(int nargout, mwArray& data, const mwArray& data_in1, const 
                           mwArray& x, const mwArray& y, const mwArray& z)
{
    mclcppMlfFeval(_mcr_inst, "crg_surf", nargout, 1, 4, &data, &data_in1, &x, &y, &z);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_wgs84_crg2html(int nargout, mwArray& data, const mwArray& data_in1, 
                                     const mwArray& file, const mwArray& opts)
{
    mclcppMlfFeval(_mcr_inst, "crg_wgs84_crg2html", nargout, 1, 3, &data, &data_in1, &file, &opts);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_wgs84_dist(int nargout, mwArray& dist, mwArray& dbeg, mwArray& 
                                 dend, const mwArray& wgs1, const mwArray& wgs2)
{
    mclcppMlfFeval(_mcr_inst, "crg_wgs84_dist", nargout, 3, 2, &dist, &dbeg, &dend, &wgs1, &wgs2);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_wgs84_invdist(int nargout, mwArray& wgs2, mwArray& dend, const 
                                    mwArray& wgs1, const mwArray& dbeg, const mwArray& 
                                    dist)
{
    mclcppMlfFeval(_mcr_inst, "crg_wgs84_invdist", nargout, 2, 3, &wgs2, &dend, &wgs1, &dbeg, &dist);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_wgs84_setend(int nargout, mwArray& data, const mwArray& data_in1, 
                                   const mwArray& dref)
{
    mclcppMlfFeval(_mcr_inst, "crg_wgs84_setend", nargout, 1, 2, &data, &data_in1, &dref);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_wgs84_wgs2url(int nargout, mwArray& url, const mwArray& wgs, const 
                                    mwArray& opts)
{
    mclcppMlfFeval(_mcr_inst, "crg_wgs84_wgs2url", nargout, 1, 2, &url, &wgs, &opts);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_wgs84_wgsxy2wgs(int nargout, mwArray& wgs, const mwArray& wgs1, 
                                      const mwArray& wgs2, const mwArray& pxy1, const 
                                      mwArray& pxy2, const mwArray& pxy, const mwArray& 
                                      eps, const mwArray& tol)
{
    mclcppMlfFeval(_mcr_inst, "crg_wgs84_wgsxy2wgs", nargout, 1, 7, &wgs, &wgs1, &wgs2, &pxy1, &pxy2, &pxy, &eps, &tol);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_wgs84_xy2wgs(int nargout, mwArray& wgs, mwArray& data, const 
                                   mwArray& data_in1, const mwArray& pxy)
{
    mclcppMlfFeval(_mcr_inst, "crg_wgs84_xy2wgs", nargout, 2, 2, &wgs, &data, &data_in1, &pxy);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_wrap(int nargout, mwArray& data, const mwArray& data_in1)
{
    mclcppMlfFeval(_mcr_inst, "crg_wrap", nargout, 1, 1, &data, &data_in1);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV crg_write(int nargout, mwArray& ier, const mwArray& data, const 
                            mwArray& file)
{
    mclcppMlfFeval(_mcr_inst, "crg_write", nargout, 1, 2, &ier, &data, &file);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV ipl_read(int nargout, mwArray& data, const mwArray& filename, const 
                           mwArray& opts)
{
    mclcppMlfFeval(_mcr_inst, "ipl_read", nargout, 1, 2, &data, &filename, &opts);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV ipl_write(int nargout, mwArray& ier, const mwArray& data, const 
                            mwArray& filename, const mwArray& type)
{
    mclcppMlfFeval(_mcr_inst, "ipl_write", nargout, 1, 3, &ier, &data, &filename, &type);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV map_wgs2html(int nargout, mwArray& file, const mwArray& llh, const 
                               mwArray& file_in1, const mwArray& opts)
{
    mclcppMlfFeval(_mcr_inst, "map_wgs2html", nargout, 1, 3, &file, &llh, &file_in1, &opts);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV sdf_add(int nargout, mwArray& sdf_out, const mwArray& sdf_in, const 
                          mwArray& blockname, const mwArray& sdf_block)
{
    mclcppMlfFeval(_mcr_inst, "sdf_add", nargout, 1, 3, &sdf_out, &sdf_in, &blockname, &sdf_block);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV sdf_cut(int nargout, mwArray& sdf_block, mwArray& sdf_out, const 
                          mwArray& sdf_in, const mwArray& blockname)
{
    mclcppMlfFeval(_mcr_inst, "sdf_cut", nargout, 2, 2, &sdf_block, &sdf_out, &sdf_in, &blockname);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV smooth_firfilt(int nargout, mwArray& y, const mwArray& x, const 
                                 mwArray& w, const mwArray& opts)
{
    mclcppMlfFeval(_mcr_inst, "smooth_firfilt", nargout, 1, 3, &y, &x, &w, &opts);
}

LIB_opencrg_CPP_API 
void MW_CALL_CONV str_num2strn(int nargout, mwArray& t, const mwArray& x, const mwArray& 
                               n)
{
    mclcppMlfFeval(_mcr_inst, "str_num2strn", nargout, 1, 2, &t, &x, &n);
}

