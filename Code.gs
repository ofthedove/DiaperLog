function test() {
  var e = {};
  e.parameter = {};
  e.parameter.data = '[1,1234]';
  e.parameter.coreid = '1f0030001647ffffffffffff';
  e.parameter.published_at = "2021-08-28T15:51:13.037Z"; // new Date().toISOString();
  doPost(e);
}

function doPost(e) {
  // e.parameter.data
  // e.parameter.coreid
  // e.parameter.published_at "2016-04-16T13:37:08.728Z"

  var publishedAt = new Date(e.parameter.published_at);
  var receivedAt = new Date();

  var dataArray = [];
  try {
    dataArray = JSON.parse(e.parameter.data);
  }
  catch(e) {
  }

  var sheet = SpreadsheetApp.getActiveSheet();

  var row = [e.parameter.coreid, publishedAt, receivedAt];

  row = row.concat(dataArray);

  sheet.appendRow(row);

  var result = {};
  result.ok = true;

  return ContentService.createTextOutput(JSON.stringify(result))
    .setMimeType(ContentService.MimeType.JSON);
}

function doGet(e) {
  var result = {};
  result.ok = true;

  return ContentService.createTextOutput(JSON.stringify(result))
  .setMimeType(ContentService.MimeType.JSON);
}
