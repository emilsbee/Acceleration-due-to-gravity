const parseRTF = require('rtf-parser')
const fs = require('fs')
var val = [];
var millis;
var g = [];

const parser = parseRTF((err, doc) => {
  if (err){
    return err
  }
  for(each in doc.content){
    // console.log(parseInt(doc.content[each].content[0].value));
    if(parseInt(doc.content[each].content) == undefined){
      console.log('problem');
      return
    } else {
      val.push(parseInt(doc.content[each].content[0].value))
      if (val.length == 2) {
        millis = val[0] + val[1]
        g.push(millis)
        console.log(millis);
        val.pop()
        val.pop()
        console.log(val);
      }
    }
  }
var sum = 0;
for( var i = 0; i < g.length; i++ ){
    sum += parseInt( g[i], 10); //don't forget to add the base
}

var avg = sum/g.length;
var firstP = 4*Math.PI*Math.PI*0.207
var avgDec = avg / 1000
var avgSq = avgDec * avgDec
// console.log(firstP / avgSq);
// console.log("Average: ", avg);
})
fs.createReadStream('data_copy.rtf').pipe(parser)
