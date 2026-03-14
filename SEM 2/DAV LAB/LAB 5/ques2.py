import pandas as pd
import numpy as np

df = pd.read_csv("cereal.csv")

cols = ["protein", "fat", "sodium", "fiber", "carbo", "sugars", "potass", "vitamins"]

print("Before preprocessing")
print(df[cols].describe())

df[cols] = df[cols].replace(-1, np.nan)
df[cols] = df[cols].fillna(df[cols].mean())

print("\nAfter replacing missing values")
print(df[cols].describe())

for col in cols:
    median = df[col].median()
    df[col] = np.where(df[col] < df[col].quantile(0.05), median, df[col])
    df[col] = np.where(df[col] > df[col].quantile(0.95), median, df[col])

print("\nAfter treating noisy values")
print(df[cols].describe())