
% Initialize parameters automatically when the model gets loaded.
%
% In the File / Model properties dialog of the model, on the tab labeled
% Callbacks, set 'MySusp_StabiSystem_RTW_params' as the Model's pre-load function.
%
% An alternative way via the Matlab command line would be
%   set_param('MySusp_StabiSystem_RTW', 'PreLoadFcn', 'MySusp_StabiSystem_RTW_params');

disp('Executing MySusp_StabiSystem_RTW_params.m for parameter initialization');

Stiffness_F = 15000;
Stiffness_R = 15000;

