
% Initialize parameters automatically when the model gets loaded.
%
% In the File / Model properties dialog of the model, on the tab labeled
% Callbacks, set 'BodyCtrl_params' as the Model's pre-load function.
%
% An alternative way via the Matlab command line would be
%   set_param('BodyCtrl', 'PreLoadFcn', 'BodyCtrl_params');

disp('Executing BodyCtrl_RTW_params.m for parameter initialization');

l0_FL = 0.3541;
Stiffness_FL = 24000.0;
l0_FR = 0.3541;
Stiffness_FR = 24000.0;
l0_RL = 0.0975;
Stiffness_RL = 25000.0;
l0_RR = 0.0975;
Stiffness_RR = 25000.0;

BodyCtrl_k = 300;

