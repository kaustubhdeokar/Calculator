### How to setup a c++ debug environment for vscode (Optional)

[Gist](https://gist.github.com/kaustubhdeokar/40d738d2220bd23c2b554003d761b086)

## REST API Calculator

This is a simple REST API calculator built using the Crow C++ microframework. It supports basic arithmetic operations, trigonometric functions, and compound interest calculations.

## Base URL
```
http://localhost:18080
```

## Endpoints

### 1. Basic Math Operations
**Endpoint:** `/basic_math`
**Method:** `GET`
**Description:** Perform basic arithmetic operations (addition, subtraction, multiplication, division).

**Request Body:**
```json
{
    "operation": "add" | "subtract" | "multiply" | "divide",
    "a": <number>,
    "b": <number>
}
```

**Example Request:**
```sh
curl -X GET -d '{"operation": "add", "a": 5, "b": 3}' http://localhost:18080/basic_math
```

**Response:**
```json
{
    "result": <number>
}
```

**Possible Arguments:**
- `operation`: The arithmetic operation to perform. Possible values are `add`, `subtract`, `multiply`, `divide`.
- `a`: The first operand (number).
- `b`: The second operand (number).

### 2. Trigonometric Functions
**Endpoint:** `/trig_functions`
**Method:** `GET`
**Description:** Perform trigonometric functions (sine, cosine, tangent).

**Request Body:**
```json
{
    "operation": "sin" | "cos" | "tan",
    "angle": <number>
}
```

**Example Request:**
```sh
curl -X GET -d '{"operation": "sin", "angle": 1.5708}' http://localhost:18080/trig_functions
```

**Response:**
```json
{
    "result": <number>
}
```

**Possible Arguments:**
- `operation`: The trigonometric function to perform. Possible values are `sin`, `cos`, `tan`.
- `angle`: The angle in radians (number).

### 3. Compound Interest Calculation
**Endpoint:** `/compound_interest`
**Method:** `GET`
**Description:** Calculate compound interest.

**Request Body:**
```json
{
    "principal": <number>,
    "rate": <number>,
    "times": <integer>,
    "years": <integer>
}
```

**Example Request:**
```sh
curl -X GET -d '{"principal": 1000, "rate": 0.05, "times": 4, "years": 5}' http://localhost:18080/compound_interest
```

**Response:**
```json
{
    "result": <number>
}
```

**Possible Arguments:**
- `principal`: The initial amount of money (number).
- `rate`: The annual interest rate (number).
- `times`: The number of times interest is compounded per year (integer).
- `years`: The number of years the money is invested or borrowed for (integer).

## Example Requests

1. **Basic Math Operations** (`/basic_math`):
   ```sh
   curl -X GET -d '{"operation": "add", "a": 5, "b": 3}' http://localhost:18080/basic_math
   ```

2. **Trigonometric Functions** (`/trig_functions`):
   ```sh
   curl -X GET -d '{"operation": "sin", "angle": 1.5708}' http://localhost:18080/trig_functions
   ```

3. **Compound Interest Calculation** (`/compound_interest`):
   ```sh
   curl -X GET -d '{"principal": 1000, "rate": 0.05, "times": 4, "years": 5}' http://localhost:18080/compound_interest
   ```

## Compilation and Running

Make sure you have the Asio library included. Here is an example Makefile:

```Makefile
CXX = g++
CXXFLAGS = -std=c++11 -pthread -I/path/to/asio/include

TARGET = calculator
SRCS = main.cpp

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)
```

Replace `/path/to/asio/include` with the actual path to the Asio include directory.

Compile and run the project:

```sh
make
./calculator
```

This will start the Crow web server on port 18080, and you can send GET requests with a body to the respective endpoints for different types of calculations.
