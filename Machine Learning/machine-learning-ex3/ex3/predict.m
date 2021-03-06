function p = predict(Theta1, Theta2, X)
%PREDICT Predict the label of an input given a trained neural network
%   p = PREDICT(Theta1, Theta2, X) outputs the predicted label of X given the
%   trained weights of a neural network (Theta1, Theta2)

% Useful values
m = size(X, 1);
num_labels = size(Theta2, 1);

% You need to return the following variables correctly 
p = zeros(size(X, 1), 1);

% ====================== YOUR CODE HERE ======================
% Instructions: Complete the following code to make predictions using
%               your learned neural network. You should set p to a 
%               vector containing labels between 1 to num_labels.
%
% Hint: The max function might come in useful. In particular, the max
%       function can also return the index of the max element, for more
%       information see 'help max'. If your examples are in rows, then, you
%       can use max(A, [], 2) to obtain the max for each row.
%
layer_0 = X;
z1 = [ones(m,1), layer_0]; %Layer0 is the layer for inputs
layer_1 = sigmoid(z1*Theta1');
z2 = [ones(m,1), layer_1];
layer_2 = sigmoid(z2*Theta2');
h = layer_2;

[max_p, index_max] = max(h,[],2);
p = index_max;

% =========================================================================


end
