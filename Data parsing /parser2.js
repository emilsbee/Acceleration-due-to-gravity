// Modules
const readline = require('readline-sync')
const fs = require('fs');

// Read file
var array = fs.readFileSync('data.txt').toString().split("\n");

// Variables
var sum = [] // The values for oscillation time summed together
var val = [] // Used in function parseData()
var pendulum_arm = readline.question('Size of the pendulum: ')  // Promting console for
var trial = readline.question('Trial nr: ')  // Promting console for

// Function for parsing raw data (half oscillations) into an array of values of complete oscillations
function parseData(data){
  for(i in data) {
      var integ = parseInt(data[i], 10);
      val.push(integ)
      if (val.length == 2) {
        var dec_1 = val[0]/1000
        var dec_2 = val[1] / 1000
        millis = dec_1 + dec_2
        sum.push(millis)
        val.pop()
        val.pop()
      } else if (val.length <= 1) {

      }
  }
  return sum
}

var parsedData = parseData(array)  // Data from parseData()


// Function for calculating the acceleration due to gravity from an array of values of oscillations
function gravity(parsedData) {
  sum = parsedData.reduce((a, b) => a + b, 0); // Sum of all oscillations
  var act_array_sz = array.length / 2
  var avg_millis = sum / act_array_sz
  var first_part = 4 * Math.PI * Math.PI * pendulum_arm
  var second_part = avg_millis * avg_millis
  var grav = first_part / second_part
  return grav
}


// Same function as above but returns the average full oscillation time
function average(parsedData) {
  sum = parsedData.reduce((a, b) => a + b, 0); // Sum of all oscillations
  var act_array_sz = array.length / 2
  var avg_millis = sum / act_array_sz
  return avg_millis
}


// Logging the values to console and writing them to a file 
console.log("Gravity: ", gravity(parsedData));
console.log("Average: ", average(parsedData));
var theRes = gravity(parsedData)
var theAvgMillis = average(parsedData)
var text = "Gravity: " + theRes + ", " + "Length: " + pendulum_arm + ", " +  "Trial: " + trial + ", " + "Average: " + theAvgMillis
fs.writeFileSync('res.txt', text)
fs.writeFile('res.txt', text, (err) => {
    if (err) throw err;
});
