function [J, grad] = costFunctionReg(initial_theta, X, y, lambda)
%COSTFUNCTIONREG Compute cost and gradient for logistic regression with regularization
%   J = COSTFUNCTIONREG(theta, X, y, lambda) computes the cost of using
%   theta as the parameter for regularized logistic regression and the
%   gradient of the cost w.r.t. to the parameters. 

% Initialize some useful values
m = length(y); % number of training examples

% You need to return the following variables correctly 
J = 0;
grad = zeros(size(initial_theta));

% ====================== YOUR CODE HERE ======================
% Instructions: Compute the cost of a particular choice of theta.
%               You should set J to the cost.
%               Compute the partial derivatives and set grad to the partial
%               derivatives of the cost w.r.t. each parameter in theta

h = sigmoid(X*initial_theta);
shift_theta = initial_theta(2:size(initial_theta),:); %%To not regularise theta0
theta_reg = [0;shift_theta]; %%after finding h then set theta0 = 0

B = log(h); C = log(1-h);
J = (1/m)*(-(y')*B-((1-y)')*C)+(lambda*((2*m)^-1))*(theta_reg)'*(theta_reg);

grad=((h-y)'*X)'/m +(lambda/m)*(theta_reg);



% =============================================================

end
