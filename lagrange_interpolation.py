def lagrange_interpolation(x_values, y_values, x):
    n = len(x_values)
    result = 0
    for i in range(n):
        term = y_values[i]
        for j in range(n):
            if i != j:
                term *= (x - x_values[j]) / (x_values[i] - x_values[j])
        result += term
    return result

# Example usage
x_points = [1, 2, 3]
y_points = [2, 3, 5]
x_interpolate = 2.7

print(f"Interpolated value at x={x_interpolate}: {lagrange_interpolation(x_points, y_points, x_interpolate)}")