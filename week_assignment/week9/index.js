function NewPromise(executorFunction) {
    let state = "pending";
    let value;
    let successCallbacks = [];
    let errorCallbacks = [];

    function resolve(result) {
        if (state !== "pending") return;

        state = "fulfilled";
        value = result;

        successCallbacks.forEach(callback => callback(result));
    }

    function reject(error) {
        if (state !== "pending") return;

        state = "rejected";
        value = error;

        errorCallbacks.forEach(callback => callback(error));
    }

    this.then = function (callback) {
        return new NewPromise((resolve, reject) => {

            if (state === "fulfilled") {
                try {
                    let result = callback(value);
                    resolve(result);
                } catch (error) {
                    reject(error);
                }
            } 
            else if (state === "pending") {
                successCallbacks.push(function (value) {
                    try {
                        let result = callback(value);
                        resolve(result);
                    } catch (error) {
                        reject(error);
                    }
                });
            }
        });
    };

    this.catch = function (callback) {
        return new NewPromise((resolve, reject) => {

            if (state === "rejected") {
                try {
                    let result = callback(value);
                    resolve(result);
                } catch (error) {
                    reject(error);
                }
            }
            else if (state === "pending") {
                errorCallbacks.push(function (error) {
                    try {
                        let result = callback(error);
                        resolve(result);
                    } catch (err) {
                        reject(err);
                    }
                });
            }
        });
    };

    try {
        executorFunction(resolve, reject);
    } catch (error) {
        reject(error);
    }
}