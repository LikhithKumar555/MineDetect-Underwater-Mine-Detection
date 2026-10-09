 # Required Libraries
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.svm import SVC
from sklearn.metrics import accuracy_score
from sklearn.impute import SimpleImputer
import joblib

# Load CSV file
data = pd.read_csv(r'C:\submarine\a\submarine_1.csv')

# Split data into features and labels
X = data.iloc[:, :-1].values  # Features (sensor values)
y = data.iloc[:, -1].values   # Labels (rock, mine, negative)

# Impute missing values
imputer = SimpleImputer(strategy='mean')  # You can use other strategies like 'median' or 'most_frequent'
X = imputer.fit_transform(X)

# Split the dataset into training and test sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=0)

# Train a SVM classifier
clf_svm = SVC(random_state=0)
clf_svm.fit(X_train, y_train)

# Make predictions on the test set
y_pred_svm = clf_svm.predict(X_test)

# Evaluate the model
accuracy_svm = accuracy_score(y_test, y_pred_svm)
print(f"Model accuracy (SVM): {accuracy_svm}")

# Save the SVM model for later use
joblib.dump(clf_svm, r'C:\submarine\a\model_svm.pkl')

