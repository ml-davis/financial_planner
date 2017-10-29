const webpack = require('webpack');

module.exports = {
  context: __dirname,
  devtool: "inline-sourcemap",
  entry: "./view/js/Index.js",
  module: {
    loaders: [
      {
        test: /\.js?$/,
        exclude: /(node_modules|bower_components)/,
        loader: 'babel-loader',
        query: {
          presets: ['react', 'es2015', 'stage-0'],
          plugins: ['react-html-attrs', 'transform-class-properties', 'transform-decorators-legacy']
        }
      }
    ]
  },
  output: {
    path: __dirname + "/view/js",
    filename: "client.min.js"
  },
  plugins: []
};
