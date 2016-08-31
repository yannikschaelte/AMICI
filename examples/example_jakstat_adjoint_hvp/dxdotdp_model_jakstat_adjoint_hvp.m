function out = dxdotdp_model_jakstat_adjoint_hvp(t,x,p,k)
%DXDOTDP_MODEL_JAKSTAT_ADJOINT_HVP
%    out = DXDOTDP_MODEL_JAKSTAT_ADJOINT_HVP(T,X,P,K)

%    This function was generated by the Symbolic Math Toolbox version 7.0.
%    31-Aug-2016 16:00:20

out = sparse([],[],[],9,17,23);
out(1) = -x(1)*am_spline_pos(t, 5.0, 0.0, p(6), 5.0, p(7), 10.0, p(8), 20.0, p(9), 60.0, p(10), 0.0, 0);
out(2) = x(1)*am_spline_pos(t, 5.0, 0.0, p(6), 5.0, p(7), 10.0, p(8), 20.0, p(9), 60.0, p(10), 0.0, 0);
out(11) = -2*x(2)^2;
out(12) = x(2)^2;
out(21) = -x(3);
out(22) = (k(1)*x(3))/k(2);
out(28) = (k(2)*x(9))/k(1);
out(31) = -x(4);
out(32) = 2*x(4) - x(5);
out(33) = x(5) - x(6);
out(34) = x(6) - x(7);
out(35) = x(7) - x(8);
out(36) = x(8) - x(9);
out(46) = -p(1)*x(1)*D([4], am_spline_pos)(t, 5.0, 0.0, p(6), 5.0, p(7), 10.0, p(8), 20.0, p(9), 60.0, p(10), 0.0, 0);
out(47) = p(1)*x(1)*D([4], am_spline_pos)(t, 5.0, 0.0, p(6), 5.0, p(7), 10.0, p(8), 20.0, p(9), 60.0, p(10), 0.0, 0);
out(55) = -p(1)*x(1)*D([6], am_spline_pos)(t, 5.0, 0.0, p(6), 5.0, p(7), 10.0, p(8), 20.0, p(9), 60.0, p(10), 0.0, 0);
out(56) = p(1)*x(1)*D([6], am_spline_pos)(t, 5.0, 0.0, p(6), 5.0, p(7), 10.0, p(8), 20.0, p(9), 60.0, p(10), 0.0, 0);
out(64) = -p(1)*x(1)*D([8], am_spline_pos)(t, 5.0, 0.0, p(6), 5.0, p(7), 10.0, p(8), 20.0, p(9), 60.0, p(10), 0.0, 0);
out(65) = p(1)*x(1)*D([8], am_spline_pos)(t, 5.0, 0.0, p(6), 5.0, p(7), 10.0, p(8), 20.0, p(9), 60.0, p(10), 0.0, 0);
out(73) = -p(1)*x(1)*D([10], am_spline_pos)(t, 5.0, 0.0, p(6), 5.0, p(7), 10.0, p(8), 20.0, p(9), 60.0, p(10), 0.0, 0);
out(74) = p(1)*x(1)*D([10], am_spline_pos)(t, 5.0, 0.0, p(6), 5.0, p(7), 10.0, p(8), 20.0, p(9), 60.0, p(10), 0.0, 0);
out(82) = -p(1)*x(1)*D([12], am_spline_pos)(t, 5.0, 0.0, p(6), 5.0, p(7), 10.0, p(8), 20.0, p(9), 60.0, p(10), 0.0, 0);
out(83) = p(1)*x(1)*D([12], am_spline_pos)(t, 5.0, 0.0, p(6), 5.0, p(7), 10.0, p(8), 20.0, p(9), 60.0, p(10), 0.0, 0);
